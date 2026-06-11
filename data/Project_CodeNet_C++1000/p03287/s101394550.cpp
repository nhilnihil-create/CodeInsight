#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
// const ll MOD = 998244353;
const double PI=3.14159265358979323846;



int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<int> A(n+10);
    rp(i, 0, n) {
        int a; cin >> a;
        A[i+1] = (A[i] + a) % m;
    }
    ll res = 0;
    map<int, int> cnt;
    cnt[0] = 1;
    rp(i, 0, n) {
        int a = A[i+1];
        if(cnt.find(a) == cnt.end()) cnt[a] = 1;
        else {
            res += cnt[a];
            cnt[a]++;
        }
    }
    cout << res << endl;
    return 0;
}
