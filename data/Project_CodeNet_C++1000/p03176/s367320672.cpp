
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<bitset> 
#include<unordered_map> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include "boost/algorithm/string.hpp"
// RAJJI KI MEHER 
#define fio ios_base::sync_with_stdio(false)
//#define mod 1000000007
#define mod1 mod
#define mod2 100000009
#define li long long int
#define ll int
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define readi(x) scanf("%d",&x)
#define  reads(x)  scanf("%s", x)
#define readl(x) scanf("%lld",&x)
#define rep(i,n) for(i=0;i<n;i++)
#define revp(i,n) for(i=(n-1);i>=0;i--)
#define myrep1(i,a,b) for(i=a;i<=b;i++)
#define myrep2(i,a,b) for(i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define MAXN 100000000000000005
#define MINN -10000000000000000
#define INTMAX 1000001000
#define pii pair<li,li>
#define pdd pair<double,double>
#define pic pair<int,char>
//#define N 5005
#define lgn 20
#define ddouble long double
#define minus minu
#define PI 3.1415926535
#define lgn 20
using namespace std;
li bit[200005]={0};
li query(li i,li n){li ans=0;while(i>0){
    ans=max(ans,bit[i]);i=i-(i&(-i));}return(ans);}
void update(li i,li v,li n){while(i<=n){bit[i]=max(bit[i],v);i=i+(i&(-i));}}    
int main(){
    li n,i,j,t,x,ans=0;readl(n);
li h[n];li b[n];for(i=0;i<n;i++) readl(h[i]);
for(i=0;i<n;i++) readl(b[i]);
for(i=0;i<n;i++){x=query(h[i]-1,n);ans=max(ans,x+b[i]);
update(h[i],x+b[i],n);}
cout<<ans;    
}