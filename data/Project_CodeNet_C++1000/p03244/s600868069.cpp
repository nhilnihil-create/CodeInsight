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
#include<cmath>
#include<cstring>
#include<set>
#include<climits>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define all(a) a.begin(),a.end()
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
/*pi*/double pi=acos(-1);
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
/*Fibonacci数列*/ll fib(ll x){ll i,fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];}
/*桁数*/ll dig(ll n){ll d=0,i=0;while(n/10>0){i++;d++;}return d;}
llfor;ll ans=0;////////////////////////////////////////////////////////////
int main(){
 ll n;
 sc(n);
 ll a[n+10];
 ll mx=0;
 rep(i,0,n){
  sc(a[i]);
  mx=max(mx,a[i]);
 }
 ll even[200000]={},odd[200000]={};
 ll mx_odd=0,sc_odd=0,mx_even=0,sc_even=0;
 ll memo1=0,memo2=0,memo3=0,memo4=0;
  
 rep(i,0,n){
  if((i+1)%2==1){
   odd[a[i]]++;
  }
  if((i+1)%2==0){
   even[a[i]]++;  
  }
 }
 vector<pair<ll,ll>>od,ev;
 rep(i,0,mx+10){
  if(odd[i]!=0)od.push_back(pair(odd[i],i));
  if(even[i]!=0)ev.push_back(pair(even[i],i));
 }
 sort(all(od));sort(all(ev));
 reverse(all(od));reverse(all(ev));
 mx_odd=od[0].first;memo1=od[0].second;
 if(distance(all(od))>1){
  sc_odd=od[1].first;memo2=od[1].second;
 }
 mx_even=ev[0].first;memo3=ev[0].second;
 if(distance(all(ev))>1){
  sc_even=ev[1].first;memo4=ev[1].second;
 } 
 
 if(memo1!=memo3)ans=n-(mx_odd+mx_even);
 else if(memo1!=memo4&&mx_odd+sc_even>=sc_odd+mx_even)ans=n-(mx_odd+sc_even);
 else if(memo2!=memo3&&mx_odd+sc_even<sc_odd+mx_even)ans=n-(sc_odd+mx_even);
 else if(memo2!=memo4)ans=n-(sc_odd+sc_even);
 pr(ans);
 return 0;}