#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int64_t A,B,C;
  cin>>A>>B>>C;
  if(C-1>=A+B){cout<<B+(A+B+1)<<endl;}
  else{cout<<C+B<<endl;}
  return 0;  
}