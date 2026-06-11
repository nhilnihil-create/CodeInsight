#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int a,b;
  cin>>a>>b;
  if(a+b==15){cout<<'+'<<endl;}
  else if(a*b==15){cout<<'*'<<endl;}
  else{cout<<'x'<<endl;}
  return 0;  
}