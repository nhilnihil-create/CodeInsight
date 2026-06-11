#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;


template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}

// doc: https://shibh308.github.io/library/library/lib/classes/compression.cpp.html
template<typename T>
struct Compression{
    vector<T> compvec;
    Compression(vector<T>& inp){//圧縮する
        compvec = inp;
        sort(compvec.begin(), compvec.end());
        compvec.erase(unique(compvec.begin(), compvec.end()), compvec.end());
    }
    int Index(T val){//圧縮を元に対応するインデックスを返す
        auto it = lower_bound(compvec.begin(), compvec.end(), val);
        return distance(compvec.begin(), it);
    }
    vector<T>& operator*(){
        return compvec;
    }
};

// doc: https://shibh308.github.io/library/library/lib/classes/bitvector.cpp.html
struct BitVector{
    vector<uint64_t> v;
    vector<int> r;
    BitVector(){}
    void build(){
        r.assign(v.size() + 1, 0);
        for(int i = 0; i < v.size(); ++i)
            r[i + 1] = r[i] + __builtin_popcountll(v[i]);
    }
    bool access(int x){
        return (v[x >> 6] >> (x & 63)) & 1;
    }
    // [0, x)の1の出現回数
    int rank(int x){
        return r[x >> 6] + __builtin_popcountll(v[x >> 6] & ((1uLL << (x & 63)) - 1));
    }
    int rank(int x, bool fl){
        return fl ? rank(x) : x - rank(x);
    }
};


// doc: https://shibh308.github.io/library/library/lib/classes/waveletmatrix.cpp.html
template <typename T, int W>
struct WaveletMatrix{

    array<BitVector, W> bv;
    array<int, W> zero_cnt;

    WaveletMatrix(vector<T>& a){
        int n = a.size();
        vector<T> v(a);
        for(int i = W - 1; i >= 0; --i){
            vector<uint64_t> b((n >> 6) + 1, 0);
            vector<T> v1, v2;
            for(int j = 0; j < n; ++j){
                ((v[j] >> i) & 1 ? v2 : v1).push_back(v[j]);
                b[j >> 6] |= uint64_t((v[j] >> i) & 1) << (j & 63);
            }
            for(int j = 0; j < v.size(); ++j)
                v[j] = (j < v1.size() ? v1[j] : v2[j - v1.size()]);
            bv[i].v = move(b);
            bv[i].build();
            zero_cnt[i] = bv[i].rank(n, 0);
        }
    }

    // [l, r)内のxの数
    int count(int l, int r, T x){
        for(int i = W - 1; i >= 0; --i){
            bool fl = (x >> i) & 1;
            int st = bv[i].rank(l, fl);
            int en = bv[i].rank(r, fl);
            l = (fl ? zero_cnt[i] : 0) + st;
            r = (fl ? zero_cnt[i] : 0) + en;
        }
        return r - l;
    }

    // [l, r)内で[0, x)を満たす値の数
    int count_lower(int l, int r, T x){
        int cnt = 0;
        for(int i = W - 1; i >= 0; --i){
            bool fl = (x >> i) & 1;
            int st = bv[i].rank(l, fl);
            int en = bv[i].rank(r, fl);
            if(fl){
                st += zero_cnt[i];
                en += zero_cnt[i];
                cnt += (bv[i].rank(r, 0) - bv[i].rank(l, 0));
            }
            l = st, r = en;
        }
        return cnt;
    }

    // [l, r)内で[x, y)を満たす値の数
    int count_range(int l, int r, T x, T y){
        return count_lower(l, r, y) - count_lower(l, r, x);
    }

    // 0-indexedでk番目に小さいものを返す
    T kth_min(int l, int r, int k){
        T ans = 0;
        for(int i = W - 1; i >= 0; --i){
            int st = bv[i].rank(l, 0);
            int en = bv[i].rank(r, 0);
            if(en - st <= k){
                k -= en - st;
                l = zero_cnt[i] + bv[i].rank(l, 1);
                r = zero_cnt[i] + bv[i].rank(r, 1);
                ans |= (1uLL << i);
            }
            else{
                l = st, r = en;
            }
        }
        return ans;
    }

    // [l, r)でのx以上最小値
    pair<T, bool> predecessor(int l, int r, T x){
        int idx = count_lower(l, r, x);
        if(idx == r - l){
            return make_pair((1uLL << W) - 1, false);
        }
        return make_pair(kth_min(l, r, idx), true);
    }

    // [l, r)でのx以下最大値
    pair<T, bool> successor(int l, int r, T x){
        int idx = count_lower(l, r, x + 1);
        if(idx == 0)
            return make_pair(0, false);
        return make_pair(kth_min(l, r, idx - 1), true);
    }
};


signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    vector<pair<int,int>> vx;
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
        vx.emplace_back(x[i], i);
    }
    sort(vx.begin(), vx.end());
    vector<int> wx, wy;
    Compression<int> cy(y);
    for(int i = 0; i < n; ++i){
        wx.emplace_back(vx[i].first);
        wy.emplace_back(cy.Index(y[vx[i].second]));
    }
    int siz = cy.compvec.size();

    WaveletMatrix<int, 20> wm(wy);

    i64 ans = 4 * INF + 5 * MOD;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j <= n; ++j){
            int lx = wx[i];
            int rx = wx[j - 1];
            for(int i2 = 0; i2 < siz; ++i2){
                for(int j2 = i2 + 1; j2 <= siz; ++j2){
                    if(wm.count_range(i, j, i2, j2) >= k){
                        int ly = cy.compvec[i2];
                        int ry = cy.compvec[j2 - 1];
                        chmin(ans, 1LL * (rx - lx) * (ry - ly));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}