#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int GCD(ll a, ll b){
  if(a<b){swap(a,b);}  
  if(a%b==0){return b;}
  else{return GCD(a%b,b);}
}

int  main(){
  ll n;cin>>n;
  vector<ll> vec(n+1);
  rep(i,n+1){cin>>vec.at(i);}
  sort(vec.begin(),vec.end());
  
  if(n==1){cout<<vec.at(1)-vec.at(0);}
  else{
  vector<ll> v(n);
  rep(i,n){
    v.at(i)=vec.at(i+1)-vec.at(i);
  }
  ll G=GCD(v[0],v[1]);
  ll g=G;
  ll i=1;
  while(i<=G){
    if(G%i!=0){i++;}
    else{
      g=G/i;
      bool b=true;
      rep(j,n){
        if(v.at(j)%g!=0){b=false;}
      }
      if(b){cout<<g;break;}
      i++;
    }
  }
  }
}