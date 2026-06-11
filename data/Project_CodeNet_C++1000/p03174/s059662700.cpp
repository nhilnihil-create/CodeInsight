#include <bits/stdc++.h>
using namespace std;
    
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n) for (int i = 0; i < n; i++)
#define repn(i, a, b) for (int i = a;i<=b;i++)
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define mem(x) memset(x, 0, sizeof(x))
#define ritr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define pai pair < int, int> ;
#define pal pair < ll, ll> ;
#define vi vector <int> ;
#define vl vector < ll > ;
#define vpai vector < pii > ;

const int mod = 1e9+7;
const int INF = INT_MAX;
const int sze = 3005;

int n;
int mat[25][25];
ll dp[21][1<<21];

ll calc(int start,int mask){
    
    if(start==n) return 1;
    if(mask==0) return 0;
    if(dp[start][mask]!=-1) return dp[start][mask];

    ll count=0;
    for(int i=0;i<n;i++){
        if(mask&(1<<i)&&mat[start][i]){
            count=(count+calc(start+1,mask^(1<<i)))%mod;
        }
    }

    return dp[start][mask]=count;
}

void solve() {
    cin>>n;
    rep(i,n) rep(j,n) cin>>mat[i][j];
    memset(dp,-1,sizeof(dp));

    cout<<calc(0,(1<<21)-1);
}

int main() {
    IOS;

    int t = 1;
    //cin >> t;
    while (t--) {
       solve();
    }

  return 0;
}