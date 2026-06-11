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
/*pi*/const double pi=acos(-1);
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
/*迷路移動*/const int dx[4]={1,0,-1,0};const int dy[4]={0,1,0,-1};
llfor;//ll ans=0;////////////////////////////////////////////////////////////
ll n,ans;
void search(ll x){
 x*=10;
 if(x>n)return;
 ll k;
 rep(k,0,3){
  ll tmp=x+3+2*k;
  bool ok=false;
  bool cnt[10]={false};
  while(tmp>0){
   cnt[tmp%10]=true;
   tmp/=10;
  }
  search(x+3+2*k);
  if(!cnt[3]||!cnt[5]||!cnt[7])continue;
  if(x+3+2*k<=n){
   ans++;
  // cout<<x+3+2*k<<" "<<ans<<" "<<cnt[3]<<" "<<cnt[5]<<" "<<cnt[7]<<endl;
  }
 }
 return;
}

int main(){
 cin>>n;
 ans=0;
 search(35);
 search(33);
 search(37);
  
 search(53);
 search(55);
 search(57);
  
 search(73);
 search(75);
 search(77);
 pr(ans);
 return 0;}