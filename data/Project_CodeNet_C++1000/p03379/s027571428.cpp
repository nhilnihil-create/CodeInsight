#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int>X(N),A(N);
  for(int i=0;i<N;i++){
    cin>>X[i];
  }
  A=X;
  sort(A.begin(),A.end());

  int s=A[N/2-1];int t=A[N/2];//cout<<s<<t<<endl;
  for(int i=0;i<N;i++){
     if(X[i]<=s){cout<<t<<endl;}
     else{cout<<s<<endl;}
  }
  return 0;  
}