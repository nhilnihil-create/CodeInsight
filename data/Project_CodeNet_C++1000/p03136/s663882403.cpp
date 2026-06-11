#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0;
  cin >> N;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  sort(A.begin(), A.end()); //小さい順
  ll ans = 0;
  rep(i,N-1){
    ans += A[i];
  }
  if(ans > A[N-1]){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}
      