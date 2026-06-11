#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1e9;
const int mod = 1000000007;

int main(){
  int N,A,B;
  cin>>N>>A>>B;
  if(A%2==B%2){cout<<"Alice"<<endl;}
  else{cout<<"Borys"<<endl;}
  return 0;                       
}