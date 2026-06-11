#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int R;
  cin>>R;
  if(R<1200){cout<<"ABC"<<endl;}
  else if(R<2800){cout<<"ARC"<<endl;}
  else{cout<<"AGC"<<endl;}
  return 0;  
}