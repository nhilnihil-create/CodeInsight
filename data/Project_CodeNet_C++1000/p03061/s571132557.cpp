#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <cmath>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int mod=1e9+7;

int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  vector<int>l(N),r(N);
  int g=0;
  for(int i=1;i<N;i++){
   g= __gcd(g,A[i-1]);
   l[i]=g;
  }
  g=0;
  for(int i=N-2;i>=0;i--){
    g=__gcd(g,A[i+1]);
    r[i]=g;
  }
  int MAX=0;
  for(int i=0;i<N;i++){
    chmax(MAX,__gcd(l[i],r[i]));
  }
  cout<<MAX<<endl;
  return 0;  
}