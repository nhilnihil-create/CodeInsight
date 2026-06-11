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
#include<string>
#include<unordered_map>
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
#define sizeoof(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/*float n乗*/ll floatpow(float x,ll n){ll i;float ans=1;rep(i,0,n)ans*=x;return ans;}
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
double ans=0;llfor;///////////////////////////////////////////////////////////
int main(){
 char s[1000010];sc(s);
 ll len=strlen(s);
 ll cnt=0; 
 bool flag=false;
 rep(i,0,len){
 // pr(cnt);pr(flag);pr(s[i]);
  if((cnt==0||cnt>=3)&&!flag&&s[i]=='A')flag=true;
  else if(cnt==0&&s[i]=='K'){cnt++;flag=false;}
  else if(cnt==1&&s[i]=='I'){cnt++;flag=false;}
  else if(cnt==2&&s[i]=='H'){cnt++;flag=false;}
  else if(cnt==3&&s[i]=='B'){cnt++;flag=false;}
  else if(cnt==4&&s[i]=='R'){cnt++;flag=false;}
  else{ pN;return 0;}
 }
 if(cnt==5)pY;
 else pN;
  
return 0;}