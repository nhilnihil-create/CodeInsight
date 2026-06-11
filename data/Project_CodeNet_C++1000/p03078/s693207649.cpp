#include<iostream>
#include<stdio.h>
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
#define M  998244353
#define rep(i,a,n) for(int i=a;i<n;i++)
#define INF 10000000000000
#define N 200005
#define vi vector<int>
#define all(v) v.begin(),v.end()
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int a[1005],b[1005],c[1005];
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int x,y,z,k;
   cin>>x>>y>>z>>k;
   rep(i,0,x)cin>>a[i];
   rep(i,0,y)cin>>b[i];
   rep(i,0,z)cin>>c[i];
   vi v;
   for(int i=0;i<x;i++)
   {
       for(int j=0;j<y;j++)
       {
           v.pb(a[i] + b[j]);
       }
   }
   sort(all(v),greater<int>());
   sort(c,c+z,greater<int>());
   priority_queue<int>pq;
   int cnt=1e6;
   for(int i=0;i<v.size() && pq.size()<3*cnt;i++)
   {
       for(int j=0;j<z && pq.size()<3*cnt;j++)
       {
           pq.push(v[i] + c[j]);
       }
   }
   while(k--)
   {
       cout<<pq.top()<<endl;
       pq.pop();
   }
}
