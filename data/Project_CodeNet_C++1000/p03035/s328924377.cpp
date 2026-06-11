#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int A,B;
  cin>>A>>B;
  if(A>=13){cout<<B<<endl;}
  else if(A>=6){cout<<B/2<<endl;}
  else{cout<<0<<endl;}
  return 0;  
}