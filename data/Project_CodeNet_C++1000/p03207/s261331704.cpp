#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N = 0,ans =0;
  cin >> N;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  sort(A.begin(), A.end()); //小さい順
  reverse(A.begin(), A.end());
  rep(i,N){
    if(i == 0){
      ans+=A[i]/2;
    }
    else{
      ans += A[i];
    }
  }
  cout << ans;
}
