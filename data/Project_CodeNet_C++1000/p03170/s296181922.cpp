#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define vl vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
const int N=100005;
ll dp[N]={};
void solve()
{
    ll n,m=0,k=0,i=1,j,p,f,x;
    ll ans=0;
    cin>>n>>k;
    ll a[n] = {};
    for(i = 0; i < n; i++) cin>>a[i];
    for(ll stones = 0; stones <= k; stones++)
    {
        for(ll j: a)
        {
            if(stones >= j && !dp[stones - j])
            {
                dp[stones] = true;
            }
        }
    }
    dp[k] ? cout<<"First": cout<<"Second";
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif 
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}