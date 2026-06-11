#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)


int main() {
  int N,M;
  cin>>N>>M;
  vector<int>A(M);
  vector<int>K(N);
  rep(i,N){
      cin>>K[i];
      vector<int>C(K[i]);
      rep(j,K[i]){
          cin>>C[j];
          A[C[j]-1]++;
      }
  }
  int cnt=0;
  rep(i,M){
      if(A[i]==N){
         cnt++;
      }
  }
  cout<<cnt<<endl;
}

