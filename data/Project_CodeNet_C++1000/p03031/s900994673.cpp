#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int>k(M);
  vector<vector<int>>s(10,vector<int>(10));
  for(int i=0;i<M;i++){
    cin>>k[i];
    for(int j=0;j<k[i];j++){
      cin>>s[i][j];
    }
  }
  vector<int>p(M);
  for(int i=0;i<M;i++){
    cin>>p[i];
  }

  int ans=0;
  for(int d=0;d<(1<<N);d++){
    vector<int>g(N);
    for(int i=0;i<N;i++){
      if((d>>i)&1){g[i]=1;}
    }
    bool ok=true;
    for(int i=0;i<M;i++){
      int cnt=0;
      for(int j=0;j<k[i];j++){
        int a=s[i][j];
        if(g[a-1]){cnt++;}
      }
      if(cnt%2!=p[i]){ok=false;}
    }
    if(ok){ans++;}
  }
  cout<<ans<<endl;
  return 0;  
}