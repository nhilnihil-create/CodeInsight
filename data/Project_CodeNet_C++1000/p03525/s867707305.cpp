#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i, a, b) for(ll i = (a); i < (ll)b; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF (1ll << 60)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using vl = vector<ll>;
using vvl = vector<vl>;
typedef double db;
typedef string str;
typedef pair<ll, ll> p;
constexpr int MOD = 1000000007;
using ll = long long;
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

void print(const std::vector<int> &v) {
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}

int count(vector<int> circ) {
    int mi = 101010;
    REP(i, circ.size()) {
        REP(j, circ.size()) {
            if(i != j) {
                int d1 = abs(circ[i] - circ[j]);
                int d2 = 24 - d1;
                int d = min(d1, d2);
                mi = min(mi, d);
            }
        }
    }
    // print(circ);
    // cout << mi << endl;
    return mi;
}

int main() {
    int N;
    cin >> N;
    // Nがかなり小さい
    vector<ll> D(N);
    vector<ll> F(N);
    map<int, int> cnt;
    REP(i, N) {
        cin >> D[i];
        cnt[D[i]]++;
    }
    // https://www.hamayanhamayan.com/entry/2017/11/27/224728
    // D_iごとにカウントするる
    //おなじD_iに三人以上いる場合は0
    //一人だけの場合は左右の二通り
    // 2^11とおりを試せばよい
    if(cnt[0] > 0) {
        cout << 0 << endl;
        return 0;
    }
    REP(i, 13) {
        if(cnt[i] > 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    // D[i]が2のときはそれを全探査
    vector<int> v;
    vector<int> cricle;
    cricle.push_back(0);
    REP(i, 13) {
        if(i == 12) {
            if(cnt[i] > 0) {
                cricle.push_back(i);
            }
        } else if(cnt[i] == 1) {
            v.push_back(i);
        } else if(cnt[i] == 2) {
            cricle.push_back(i);
            cricle.push_back(24 - i);
        }
    }
    // print(cricle);
    // print(v);
    int ans = 0;
    if(v.size() == 0) {
        cout << count(cricle) << endl;
        return 0;
    }
    REP(msk, 1 << v.size()) {
        vector<int> tmp = cricle;
        REP(j, v.size()) {
            if(msk & (1 << j)) {
                tmp.push_back(v[j]);
            } else {
                tmp.push_back(24 - v[j]);
            }
        }
        ans = max(ans, count(tmp));
    }
    cout << ans << endl;
    return 0;
}