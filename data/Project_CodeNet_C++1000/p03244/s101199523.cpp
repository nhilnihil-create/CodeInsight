#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
int n;
  ll ans=0;
  cin>>n;
  vin v(n);
  rep(i,n) cin>>v[i];
  map<int,int> mp1,mp2;
  for(int i=0;i<n;i+=2){
   mp1[v[i]]++; 
  }
  for(int j=1;j<n;j+=2){
   mp2[v[j]]++; 
  }
  int cnt1=0,cnt2=0;
  int key1=0,key2=0;
  int ar1=0,ar2=0;
  for(auto v:mp1){
    if(v.second>=cnt1){
     
     cnt1=v.second;
      key1=v.first;
    }
  }
  for(auto v:mp2){
    if(v.second>=cnt2){
      
     cnt2=v.second;
      key2=v.first;
    }
  }
  if(key1!=key2){
    
     ans=n-cnt1-cnt2;
  }
  else{//key1==key2
    mp1[key1]=0;
    mp2[key1]=0;
    for(auto v:mp1){
    if(v.second>=ar1){
     
     ar1=v.second;
      
    }
  }
  for(auto v:mp2){
    if(v.second>=ar2){
      
     ar2=v.second;
      
    }
  }
    ans=n-max(ar1+cnt2,ar2+cnt1);
  }
    
    
    //cout<<ar1<<" "<<ar2<<" "<<cnt1<<" "<<cnt2<<endl;
    cout<<ans<<endl;
}


