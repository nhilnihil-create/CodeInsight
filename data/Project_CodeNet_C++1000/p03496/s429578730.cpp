#include<bits/stdc++.h>
using namespace std;
#define  ll long long
typedef pair<ll,ll> P;
int main(){
ll n,mi=10000000,ma=-10000000,mii,maa;
  cin>>n;
  ll a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(mi>=a[i]){
      mi=a[i];
      mii=i;
    }
    if(ma<a[i]){
      ma=a[i];
      maa=i;
    }
  }
  vector<P> p;
  bool f=true;
  if(mi<0&&ma>0){
    if(abs(mi)>ma){
      f=false;
      while(mi<a[n-1]){
        a[n-1]+=mi;
        p.push_back(P(mii+1,n));
      }
    }else{
      while(ma>a[0]){
        a[0]+=ma;
        p.push_back(P(maa+1,1));
      }
    }
  }else if(mi<0){
    f=false;
    while(mi<a[n-1]){
      a[n-1]+=mi;
      p.push_back(P(mii+1,n));
    }
  }else if(ma>0){
    while(ma>a[0]){
      a[0]+=ma;
      p.push_back(P(maa+1,1));
    }
  }
  if(f){
    for(int i=1;i<n;i++){
      if(a[i-1]>a[i]){
        while(a[i-1]>a[i]){
          a[i]+=a[i-1];
          p.push_back(P(i,i+1));
        }
      }
    }
  }else{
    for(int i=n-1;i>0;i--){
      if(a[i-1]>a[i]){
        while(a[i-1]>a[i]){
          a[i-1]+=a[i];
          p.push_back(P(i+1,i));
        }
      }
    }
  }
  cout<<p.size()<<endl;
  for(int i=0;i<p.size();i++){
    cout<<p[i].first<<" "<<p[i].second<<endl;
  }
}