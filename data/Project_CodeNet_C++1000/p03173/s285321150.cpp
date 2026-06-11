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
const ll INF = 1e15;
const int sze = 3005;

void solve() {
    int n;
    cin>>n;
    ll dp[n+5][n+5];
    
    ll arr[n];
    mem(arr);
    rep(i,n) cin>>arr[i];
    ll pre[n];
    pre[0]=arr[0];
    repn(i,1,n-1) pre[i]=pre[i-1]+arr[i];

    memset(dp,0,sizeof(dp));
    rep(i,n) rep(j,n) dp[i][j]=INF;
    rep(i,n) dp[i][i]=0;

    //rep(i,n) cout<<pre[i]<<" ";

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            for(int k=i+1;k<=j;k++){
                ll x=0;
                if(i!=0)
                x=pre[i-1];
                dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]+pre[j]-x);
                //cout<<"hello\n";
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
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