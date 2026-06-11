#include<bits/stdc++.h>
using namespace std;
#define ll long long

pair<ll,ll> sum(pair<ll,ll> a,pair<ll,ll> b){
  pair<ll,ll> c;
  c.first=(a.first*b.second+a.second*b.first)/__gcd(a.second,b.second);
  c.second=a.second*b.second/__gcd(a.second,b.second);
  return c;
}

int main(){
  ll n,k;
  cin >> n >> k;
  pair<ll,ll> s,t;
  if(k>n){
    s.first=0;
    s.second=1;
  }else{
    s.first=(n-k+1)/__gcd(n-k+1,n);
    s.second=n/__gcd(n-k+1,n);
  }
  //cout << s.first << "/" << s.second;
  ll p=2;
  while(k>1){
    t.first=(min(n,k-1)-min(n,(k-1)/2))/__gcd(min(n,k-1)-min(n,(k-1)/2),p*n);
    t.second=p*n/__gcd(min(n,k-1)-min(n,(k-1)/2),p*n);
    //cout << "+" << t.first << "/" << t.second << endl;
    s=sum(s,t);
    k=(k+1)/2;
    p *= 2;
    //cout << s.first << "/" << s.second;
  }
  
  double r=(double)s.first/s.second;
  printf("%.12lf",r);
}