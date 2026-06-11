#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, z, w;
    cin >> n >> z >> w;
    vi a(n);
    rep(i, n) cin >> a[i];
    if (n == 1) {
        cout << abs(a[n-1] - w) << endl;
        return 0;
    }
    cout << max(abs(a[n-2] - a[n-1]), abs(a[n-1] - w));
}