#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;
const int mod = 1e9+7;

int n;
double dp[305][305][305];

double dfs(int i, int j, int k) {
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (i == 0 && j == 0 && k == 0) return 0.0;
    double res = 0;
    if (i > 0) res += dfs(i-1,j,k) * i;
    if (j > 0) res += dfs(i+1,j-1,k) * j;
    if (k > 0) res += dfs(i,j+1,k-1) * k;
    res += n;
    res /= i+j+k;
    
    return dp[i][j][k] = res;
}

int main() {
    cin >> n;
    vint ct(4);
    rep(i,n) {
        int a; cin >> a;
        ct[a]++;
    }
    rep(i,305)rep(j,305)rep(k,305) dp[i][j][k] = -1;
    printf("%.10f\n",dfs(ct[1],ct[2],ct[3]));
}