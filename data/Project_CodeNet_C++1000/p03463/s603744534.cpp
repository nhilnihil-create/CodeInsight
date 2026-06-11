#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int main() {
  int N,A,B;
  cin>>N>>A>>B;
  if((A-B+1)%2!=0){cout<<"Alice"<<endl;}
  else{cout<<"Borys"<<endl;}
  return 0;}