#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう
//a=0x61=97 '0'=0x30=48
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef string str;
typedef pair<int,int> pairii;
typedef vector<int> veci;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  int p,q,r,s,t;
  p=a%10;q=b%10;r=c%10;s=d%10;t=e%10;
  p==0?p=10:p=p;
  q==0?q=10:p=p;
  r==0?r=10:p=p;
  s==0?s=10:p=p;
  t==0?t=10:p=p;
  int x=min(p,min(q,min(r,min(s,t))));
  x==10?x=0:x=x;
  p==10?p=0:p=p;
  q==10?q=0:p=p;
  r==10?r=0:p=p;
  s==10?s=0:p=p;
  t==10?t=0:p=p;
  if(x==p){cout<<a+(b/10+(bool)q)*10+(c/10+(bool)r)*10+(d/10+(bool)s)*10+(e/10+(bool)t)*10<<endl;}
else  if(x==q){cout<<b+(a/10+(bool)p)*10+(c/10+(bool)r)*10+(d/10+(bool)s)*10+(e/10+(bool)t)*10<<endl;}
else  if(x==r){cout<<c+(b/10+(bool)q)*10+(a/10+(bool)p)*10+(d/10+(bool)s)*10+(e/10+(bool)t)*10<<endl;}
else  if(x==s){cout<<d+(b/10+(bool)q)*10+(c/10+(bool)r)*10+(a/10+(bool)p)*10+(e/10+(bool)t)*10<<endl;}
else  if(x==t){cout<<e+(b/10+(bool)q)*10+(c/10+(bool)r)*10+(d/10+(bool)s)*10+(a/10+(bool)p)*10<<endl;}
return 0;}