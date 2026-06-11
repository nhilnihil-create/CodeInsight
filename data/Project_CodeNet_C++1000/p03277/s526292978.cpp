#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0, i##_range = (n); i < i##_range; i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

template<typename Monoid>
struct SegmentTree{ //セグメント木
private:
    int sz = 1; vector<Monoid> node;
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func pick; const Monoid init; //モノイドに対する操作と、その単位元
public:
    SegmentTree(vector<Monoid> vec, const Func f, const Monoid m): pick(f), init(m) {
        while(sz < (int)vec.size())sz <<= 1;
        node = vector<Monoid>(sz * 2 - 1, init);
        for(int i = 0; i < (int)vec.size(); i++){
            node[i + sz - 1] = vec[i]; 
        }
        for(int i = sz - 2; i >= 0; i--){
            node[i] = pick(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }
    void initialize(){
        fill(node.begin(), node.end(), init);
    }
    void update(int i, Monoid v){ //単一の要素を変更する
        for(node[(i += sz) - 1] = v; i >>= 1;){
            node[i - 1] = pick(node[i * 2 - 1], node[i * 2]);
        }
    }
    void add(int i, Monoid v){ //単一の要素にある値を加える
        update(i, node[i + sz - 1] + v);
    }
    Monoid get(int l, int r){ //区間取得
        Monoid vl = init, vr = init;
        for((l += sz), (r += sz); l < r; (l >>= 1), (r >>= 1)){
            if(l & 1)vl = pick(vl, node[(l++) - 1]);
            if(r & 1)vr = pick(node[(--r) - 1], vr);
        }
        return pick(vl, vr);
    }
    inline Monoid operator [] (int i){ //[]でアクセス
        return node[i + sz - 1];
    }
};

int main(){

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)cin >> A[i];

    vector<int> seg_vec(2 * N + 1, 0);
    auto seg_func = [](int x, int y){ return x + y; };
    SegmentTree<int> seg(seg_vec, seg_func, 0);

    auto check = [&](int x){
        int now = N;
        long long res = 0;
        seg.initialize();
        seg.add(now, 1);
        rep(i, N){
            if(A[i] >= x)now++;
            else now--;
            res += seg.get(0, now + 1);
            seg.add(now, 1);
        }
        return res * 2 >= (long long)N * (N + 1) / 2;
    };

    int lb = 0, ub = 1000000007;
    while(ub - lb > 1){
        int md = (lb + ub) / 2;
        if(check(md))lb = md;
        else ub = md;
    }

    cout << lb << endl;
    return 0;

}