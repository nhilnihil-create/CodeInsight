#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const ll inf = 1e9;
const int MAX_N = 500;

int main() {
    int n, k; cin >> n >> k;
    vint a(n);
    rep(i,n) cin >> a[i];
    cout << (n-1+k-2)/(k-1) << endl;
}