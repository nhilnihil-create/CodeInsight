#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define EPS 1e-9
#define INF  1e15 +1    /// 10^15 + 1
#define INF2 ((ll)1)<<63 /// 2^63
#define all(a)  a.begin(),a.end()
#define bit(i,j) ((i)&((ll)1<<j))
#define setbit(i,j) ((i)|((ll)1<<j))
#define forn(i,n) for(int i=0;i<n;i++)
#define fo(i,a,b) for(int i=a;i<b;i++)
#define dbg(x) cout << #x"=" << x << '\n';
#define dbg2(x,y) cout << #x"=" << x << " " << #y"=" << y << '\n';
#define dbg3(x,y,z) cout << #x"=" << x << " " << #y"=" << y << " " << #z"=" << z << '\n';
const int MOD = 1000000007;
const int mod = 998244353;
const int nala5 = 1e5 +5;

typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector < vi > vvi;
typedef vector < vll > vvll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
typedef vector < pii > vpii;
typedef vector < pll > vpll;
typedef vector < vpii > vvpii;
typedef vector < vpll > vvpll;
typedef vector < set <int> > vsi;
typedef vector < set <ll> > vsll;

int main(){
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    string s,t;
    int n,m;
    cin>>s>>t;
    n = s.size(); m = t.size();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    vvpii cor(n+1);
    for(int i=0;i<=n;i++){
        cor[i].resize(m+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1] && dp[i-1][j-1] + 1 > dp[i][j]){ dp[i][j] = dp[i-1][j-1] + 1; cor[i][j] = mp(i-1,j-1); }
            if(dp[i-1][j] > dp[i][j]){ dp[i][j] = dp[i-1][j]; cor[i][j] = mp(i-1,j); }
            if(dp[i][j-1] > dp[i][j]){ dp[i][j] = dp[i][j-1]; cor[i][j] = mp(i,j-1); }
        }
    }
    string res="";
    int x=n, y=m;
    while(x > 0 && y > 0){
        if(s[x-1] == t[y-1]){
            res+=s[x-1];
        }
        int a = cor[x][y].fi, b=cor[x][y].se;
        x = a; y = b;
    }
    reverse(all(res));
    cout<<res<<'\n';
}	
