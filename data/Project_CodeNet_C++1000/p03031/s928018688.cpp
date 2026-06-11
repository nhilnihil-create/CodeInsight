#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>func(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p;
}

int main() {
  int N,M;
  cin>>N>>M;
  vector<vector<int>>s(M);
  for(int i=0;i<M;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      int a;
      cin>>a;
      a--;
      s[i].push_back(a);
    }
  }
  vector<int>p(M);
  for(int i=0;i<M;i++){
    cin>>p[i];
  }
  int ans=0;
  for(int t=0;t<(1<<N);t++){
    bool ok=true;
    for(int i=0;i<M;i++){
      int cnt=0;
      for(auto v:s[i]){
        if((t>>v)&1){cnt++;}
      }
      if(cnt%2!=p[i]){ok=false;}
    }
    if(ok){ans++;}
  }
  cout<<ans<<endl;
  return 0;
}