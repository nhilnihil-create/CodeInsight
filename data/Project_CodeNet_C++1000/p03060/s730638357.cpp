#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;


int main() {
  int n;
  cin>>n;
  vector<int>v(n);
  vector<int>c(n);
  for(int i=0;i<n;i++){
     cin>>v[i];
  }
  for(int i=0;i<n;i++){
     cin>>c[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
   if(v[i]>c[i]){ans+=v[i]-c[i];}
  }
  cout<<ans<<endl;
  return 0;
  }