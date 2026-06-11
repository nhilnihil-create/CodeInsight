#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
/*---------------------DEBUGGING--------------------------------------------*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/*-------------------------------------------------------------------------------------*/
//#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pcc pair<char,char>
#define F first
#define S second
#define int long long
#define pi 3.141592653589793238462643383279502
#define M  1000000007
#define rep(i,a,n) for(int i=a;i<n;i++)
#define INF 10000000000000
#define N 100005
#define vi vector<int>
#define all(v) v.begin(),v.end()
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
vi adj[N];int p[N];
vi v;map<int,int>mp;
bool vis[N]={false};
int dfs(int x)
{
    vis[x]=true;
    v.pb(x);mp[p[x]]=1;
    for(auto y:adj[x])
    {
        if(!vis[y])
            dfs(y);
    }
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,m;
   cin>>n>>m;
   rep(i,1,n+1)cin>>p[i];
   rep(i,0,m)
   {
       int u,v;
       cin>>u>>v;
       adj[u].pb(v);
       adj[v].pb(u);
   }
   int cnt=0;
   for(int i=1;i<=n;i++)
   {
       if(!vis[i])
       {
           v.clear();mp.clear();
           dfs(i);
           for(auto x:v)
           {
               if(mp[x])cnt++;
           }
       }
   }
   cout<<cnt<<endl;

}

