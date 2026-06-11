#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define mem(x,y) for(int i=0;i<x.size()i++){ x[i]=y; }
#define fo(i, l, r)  for((i) = (l); (i) < (r); (i)++)
#define fok(i,r,k)  for((i) = 0; (i) < (r); (i)=i+(k))
#define prnt(a,n)  { for(int i=0;i<n;i++){ cout<<a[i]<<" "; } cout<<endl; } 
#define mp make_pair
#define pb push_back
#define pi pair<int,int> 
#define pll pair<long long,long long>
#define vi vector<int> 
#define vl vector<long long>
#define vpl vector<pair<long long,long long>> 
#define vpi vector<pair<int,int>> 
#define all(x) x.begin(),x.end()
#define f first
#define s second
#define br cout<<endl;
#define io { freopen("input.txt","r",stdin);  freopen("output.txt","w",stdout); }
ll modexpo(ll x,ll y,ll m){    x=x%m;if(y==0){return 1;}if(y%2==0){return modexpo(x*x,y/2,m); }else{    return  (x*modexpo(x*x,y/2,m))%m; }}
const int mod  = 1e9+7;
const int maxn = 1e5 + 10;

int n,k; 
int a[maxn]; 
int main()
{
fastio; 
/*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif */
int i,j,mn=0;
cin>>n>>k;
fo(i,0,n)
{ 
    cin>>a[i]; 
    if(a[i]<a[mn]){mn = i;}
}
i = 0; int ans = 0;
while(i<n-1)
{
i = i+(k-1);
ans++; 
}
cout<<ans;
return 0;
}
//g++ -g b.cpp -o b.exe