#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int K;
  cin>>K;
  vector<int64_t>A(K);
  for(int i=0;i<K;i++){
    cin>>A[i];
  }
  int64_t MIN=A[K-1],MAX=A[K-1];
  if(A[K-1]!=2){cout<<-1<<endl;return 0;}
  for(int i=K-1;i>=0;i--){
    int64_t x=(MIN+A[i]-1)/A[i]*A[i];
    int64_t y=MAX/A[i]*A[i];
    MIN=x;
    MAX=y+A[i]-1;
    if(x>y){cout<<-1<<endl;return 0;}
  }

  cout<<MIN<<" "<<MAX<<endl;
  return 0;  
}