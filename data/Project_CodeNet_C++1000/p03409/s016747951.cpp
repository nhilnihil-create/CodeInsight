#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<functional>
#include<limits.h>
#include<stdlib.h>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j,k
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define sort(a) sort(a.begin(),a.end())
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
///////////////////////////////////////////////////////////
int main(){
 ll n;sc(n);
 ll p,q;llfor;
 llpvec a(n),c(n);
 bool flag1[1000]={false},flag2[1000]={false};
 rep(i,0,n){
  sc(p);sc(q);a[i]={p,q};
 }
 rep(i,0,n){
  sc(p);sc(q);c[i]={p,q};
 }
 sort(a);sort(c);
 ll o,r;
 ll maxx,maxy;
 rrp(i,n,0){
  maxx=990;maxy=990;
  o=a[i].first;p=a[i].second;
  if(!flag1[i]){
   rrp(j,n,0){
    if(!flag2[j]){
     q=c[j].first;r=c[j].second;
     if(o<q&&p<r){
      if(maxy>r||maxy==990){maxy=r;maxx=j;}
     }
    }
   }
   //printf("%lld %lld\n",i,maxx);
   flag1[i]=true;flag2[maxx]=true;
  }
 }
 ll ans=0;
 rep(i,0,n){
  if(flag2[i]){ans++;}
 }
 pr(ans);
  
return 0;}