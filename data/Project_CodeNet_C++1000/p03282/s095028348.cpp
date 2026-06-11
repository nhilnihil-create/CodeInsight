#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
  string s;
  int64_t K;
  cin>>s>>K;
  
  for(int i=0;i<min((int64_t)s.size(),K);i++){
    if(s[i]>='2'){cout<<s[i]<<endl;return 0;}
  }
  cout<<1<<endl;
  

  return 0;}