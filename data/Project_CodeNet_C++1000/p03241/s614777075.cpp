#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int64_t N,M;
  cin>>N>>M;
  int MAX=0;
  for(int i=1;i*i<=M;i++){
    if(M%i==0){
      int r=M/i;
      if(i*N<=M){chmax(MAX,i);}
      if(r*N<=M){chmax(MAX,r);}
    }
  }
  cout<<MAX<<endl;
  return 0;  
}