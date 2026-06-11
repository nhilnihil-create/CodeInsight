#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  int N = 0;
  cin >> N;
  vector<int>A(N);
  rep(i,N){
    cin >> A[i];
  }
  vector<int>B(N);
  rep(i,N){
    cin >> B[i];
  }
  int ans = 0,Ans = 0;
  rep(i,N){
    ans = 0;
    for(int j = 0;j <= i; j++){
      ans += A[j];
    }
    for(int k = i;k < N; k++){
      ans += B[k];
    }
    Ans = max(ans,Ans);
  }
  cout << Ans;
}