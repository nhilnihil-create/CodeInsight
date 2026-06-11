#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main() {
  ll n; cin>>n;
  vector<ll> v(n);
  rep(i,n){cin>>v[i];}
  ll sum=0;
  rep(i,n){
    ll a; cin>>a;            
    v[i]-=a;           
    sum+=v[i];
  }    
  sort(v.begin(),v.end());
  //cout<<sum<<endl;
  ll ans=0;
  if(sum<0){ans=-1;}
  else{
    ll minus=0;
    int i=0;
    while(true){
      if(v[i]<0){minus+=v[i];i++;}
      else{break;}
    }
    //cout<<i;
    int j=n-1;
    while(minus<0){
      if(v[j]>0){minus+=v[j];j--;}
      else{break;}
    }
    //cout<<j;
    ans=i+n-j-1;
  }
  cout<<ans;
}
  