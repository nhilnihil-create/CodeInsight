#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  ll N = 0,K = 0;
  cin >> N >> K;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  vector<ll>sum(N-K+1);
  rep(i,N-K+1){
    if(A[i]<0 && A[i+K-1]>=0){
      sum[i] = 2*min(abs(A[i]),abs(A[i+K-1])) + max(abs(A[i]),abs(A[i+K-1]));
    }
    else{
      sum[i] = max(abs(A[i+K-1]),abs(A[i]));
    }
  }
  sort(sum.begin(), sum.end());
  cout << sum[0];
}