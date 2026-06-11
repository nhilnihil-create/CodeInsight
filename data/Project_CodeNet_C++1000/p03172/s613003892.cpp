
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include <cmath>
#include<string.h>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include<climits>
#include <iomanip>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include <cmath>
#include<string.h>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include<climits>
#include <iomanip>
#include <unordered_set>




using namespace std;
#define ll long long
#define clr(x) memset(x, 0, sizeof(x))
#define tcase ll t;cin>>t;while(t--)
#define all(v) v.begin(),v.end()
#define GCJ ll t;cin>>t;for(ll H=1;H<=t;H++){cout<<"CASE #"<<H<<": ";solve();}
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define endl "\n"
//comment out the above line when coding probs which require flushing the output
#define prarr(a,n) for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
#define remDup(v) sort(all(v));v.resize(unique(all(v))-v.begin());
#define vi vector<ll>
#define pii pair<ll, ll>
#define vii vector<pii>
#define vvi vector<vector<ll>>
#define rep(i,n) for(ll i=0;i<n;i++)
#define crep(i,x,n) for(ll i=x;i<n;i++)
#define revrep(n,i) for(ll i=n-1;i>=0;i--)
#define crevrep(n,x,i) for(ll i=n-1;i>=x;i--)
#define ss second
#define ff first
#define incr(x,y) x=max(x, y)
#define decr(x,y) x=min(x, y)
#define pb push_back


/*
 void USACO(string s) {
 fast;
 
 freopen((s+".in").c_str(),"r",stdin);
 freopen((s+".out").c_str(),"w",stdout);
 }
 */


const ll mod = 1000000007;
ll n,k;
ll dp[101][100010];
ll pre[101][100010]={{0}};
ll a[101]={0};




void solve()
{
    memset(dp, 0, sizeof(dp));
    cin>>n>>k;
    crep(i,1,n+1)
    {
        cin>>a[i];
    }
    
    crep(i,1,n+1)
    {
        dp[i][0]=1;
        pre[i][0]=1;
        
    }
    
    rep(i,k+1)
    {
        dp[1][i]=(i<=a[1]);
        pre[1][i]=dp[1][i];
    }
    
    crep(i,1,n+1)
    {
        crep(j,1, k+1)
        {
            pre[i][j]=pre[i][j-1]+dp[i][j];
        }
        
    }

    
    for(ll i=2;i<=n;i++)
    {
        for(ll j=1;j<=k;j++)
        {

            ll l=min(a[i], j);
            
            //dp[i][j]=(((pre[i-1][j]%mod)-(pre[i-1][j-l]%mod)%mod)+dp[i-1][j-l]%mod)%mod;
            dp[i][j]=(((pre[i-1][j]+mod-pre[i-1][j-l])%mod)+(dp[i-1][j-l]%mod))%mod;
            
            pre[i][j]=((pre[i][j-1]%mod)+(dp[i][j]%mod))%mod;
        }
    }
    
    
    cout<<dp[n][k]%mod<<endl;

}


int main()
{
    //tcase
    //{
    solve();
    //}
}


















