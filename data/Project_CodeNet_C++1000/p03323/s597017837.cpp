#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long 
#define mem(x,y) for(int i=0;i<x.size()i++){ x[i]=y; }
#define fo(i, l, r)  for((i) = (l); (i) < (r); (i)++)
#define fok(i,r,k)  for((i) = 0; (i) < (r); (i)=i+(k))
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

int a,b;
int main()
{
fastio; 

int i,j;
cin>>a>>b;
if(a>8 || b>8)
{
    cout<<":("<<endl;
}
else
cout<<"Yay!";

return 0;
}
//g++ -g a.cpp -o a.exe
