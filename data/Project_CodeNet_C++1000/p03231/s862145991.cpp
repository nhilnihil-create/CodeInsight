#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int64_t N,M;
  cin>>N>>M;
  string s,t;
  cin>>s>>t;
  int g=__gcd(N,M);
  int64_t L=N*M/g;
  for(int i=0;i<g;i++){
    if(s[i*N/g]!=t[i*M/g]){cout<<-1<<endl;return 0;}
  }
  cout<<L<<endl;
  return 0;
}