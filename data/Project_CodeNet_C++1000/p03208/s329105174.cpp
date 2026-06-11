#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main(){
  ll N = 0, M = 0, ans1 = 0, ans2 = 0;
  cin >> N >> M;
  vector<ll>A(N);
  rep(i,N){
    cin >> A[i];
  }
  sort(A.begin(), A.end()); //小さい順
  vector<ll>s(N);
  rep(i,N-1){
    s[i] = A[i+1] - A[i];
  }
  ans2 = 1000000000;
  rep(i,N-M+1){
    ans1 = 0;
    rep(j,M-1){
      ans1 += s[i+j];
    }
    ans2 = min(ans2,ans1);
  }
  cout << ans2;
}