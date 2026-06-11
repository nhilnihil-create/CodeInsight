//#define opti
#ifdef opti
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#endif

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long long int LL;
typedef unsigned long long int ull;
ll power(ll x,ll y,ll p){ll r=1; x=x%p; while(y){ if(y&1) r= r*x%p; y=y>>1; x=x*x%p; } return r; }
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;*/

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int csrand(int l=0, int r=1e9){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

#define IO              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FILEIO          freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define all(v)          v.begin(),v.end()
#define PR(a)           cout<<"("<<a<<")";
#define ED              cout<<'\n';
#define endl            '\n'
#define loop(j,a,n)     for(int j=a;j<=n;j++)
#define loop1(j,a,n)    for(int j=a;j>=n;j--)
#define fr1(j,n)        for(int j=0;j<n;j++)
#define fr(n)           for(int i=0;i<n;i++)
#define trav(x,s)       for(auto x:s)
#define SC(n)           scanf("%d",&n)
#define PB              push_back
#define MP              make_pair
#define pii             pair<int,int>
#define pll             pair<long long int,long long int>
#define F               first
#define S               second 
#define binf            2000000000000000001
#define mod             1000000007

vector<ll> ind,wt,val,sd;
int n;
ll dp[1123][32234];

bool comp(int i,int j)
{
        return wt[i]+sd[i]> wt[j]+sd[j];
}   

ll solve(int i,int s)
{
    if(s<0) return -1e15;
    if(i==n) return 0;  
    int k=ind[i];
    if(dp[i][s]!=-1) return dp[i][s];
    dp[i][s]= solve(i+1,s);
    if(wt[k]<=s)
    dp[i][s]=max(dp[i][s] ,   val[k]+ solve(i+1, min(sd[k],s-wt[k]) ) );
    return dp[i][s];
}   


int main() 
{
    IO
 

    memset(dp,-1,sizeof(dp));
    cin>>n;
    ind.resize(n);
    wt.resize(n);
    val.resize(n);
    sd.resize(n);

    for(int i=0;i<n;i++)
    {
        ind[i]=i;
        cin>>wt[i]>>sd[i]>>val[i];
    }

    sort(all(ind),comp);


    ll ans=solve(0,21122);

    cout<<ans<<endl;

}




 