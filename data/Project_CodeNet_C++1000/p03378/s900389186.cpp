#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
  int N,M,X;
  cin>>N>>M>>X;
  vector<int>A(M);
  rep(i,M){
      cin>>A[i];
  }
  sort(A.begin(),A.end());
  int cnt=0;
  int cn=0;
  rep(i,M){
      if(A[i]<X){
          cnt++;
      }
      else{
          cn++;
      }
  }
  cout<<min(cnt,cn)<<endl;
}

