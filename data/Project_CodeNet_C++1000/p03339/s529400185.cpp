#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 100005;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vvint ct(2,vint(n+1,0));
    REP(i,n+1) {
        rep(j,2) ct[j][i] = ct[j][i-1];
        if (s[i-1] == 'W') ct[0][i]++;
        if (s[i-1] == 'E') ct[1][i]++;
    }
    int ans = inf;
    rep(i,n) {
        ans = min(ans,ct[0][i]+(ct[1][n]-ct[1][i+1]));
    }
    cout << ans << endl;
}