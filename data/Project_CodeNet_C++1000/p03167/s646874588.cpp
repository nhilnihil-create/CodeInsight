#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#define ios   ios_base::sync_with_stdio(false);  cin.tie(0);    cout.tie(0);
typedef   long long int ll;
using namespace std;
const int M=1e9+7;
const int N=1e3+5;
#define fi first
#define se second
#define pb push_back
#define endl "\n"
char a1[N][N];
ll a2[N][N];
int main()
{
   ll h,w;cin>>h>>w;
   for(ll i=1;i<=h;++i)
   {
       for(ll j=1;j<=w;++j)
       {
           cin>>a1[i][j];
       }
   }
   a2[1][1]=1;
   for(ll i=1;i<=h;++i)
   {
       for(ll j=1;j<=w;++j)
       {
           if((i!=1 || j!=1) && a1[i][j]=='.')
           {
               a2[i][j]=(a2[i-1][j]+a2[i][j-1])%M;
           }
       }
   }
   cout<<a2[h][w];
}