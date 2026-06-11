#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
  if(b>a)swap(a,b);
  if(a%b==0)return b;
  return gcd(b,a%b);
}
int main(){
  ll t;cin>>t;
  for(ll i=0;i<t;i++){
    ll a,b,c,d;cin>>a>>b>>c>>d;
    if(a<b){
      cout<<"No"<<endl;
      continue;
    }
    if(b>d){
      cout<<"No"<<endl;
      continue;
    }
    if(b<=c+1){
      cout<<"Yes"<<endl;
      continue;
    }
    ll e=gcd(b,d);
    ll wa=a%b;
    if(c<wa){
      cout<<"No"<<endl;
      continue;
    }
    ll syo=(c-wa)/e;
    ll ki=wa+e*syo;
    ki+=e;
    if(ki>c&&ki<b){
      cout<<"No"<<endl;
      continue;
    }
    cout<<"Yes"<<endl;
  }
}
    
    
    
    