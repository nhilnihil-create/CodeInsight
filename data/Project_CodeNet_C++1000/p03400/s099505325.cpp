#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;
const int64_t INF=1e18;

int main() {
  int N,D,X;
  cin>>N>>D>>X;
  int sum=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    sum++;
    sum+=(D-1)/a;
  }
  cout<<sum+X<<endl;
  return 0;  
}