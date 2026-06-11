#include <bits/stdc++.h>
using namespace std;
#include <math.h>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int64_t INF = 1LL << 60;

int main() {
  int N;
  cin>>N;
  vector<int>a(N);
  int64_t sum=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    sum+=a[i]-1;
  }
  cout<<sum<<endl;
  

  return 0;}