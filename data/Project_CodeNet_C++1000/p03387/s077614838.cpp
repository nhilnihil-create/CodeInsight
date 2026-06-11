#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int A,B,C;
  cin>>A>>B>>C;
  int t=A+B+C;
  int m=max({A,B,C});
  if((3*m-t)%2==0){cout<<(3*m-t)/2<<endl;}
  else{cout<<((m+1)*3-t)/2<<endl;}
  
  return 0;  
}