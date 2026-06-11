#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  sort(A.begin(), A.end());
  int ans = A[0];
  for (int i = 1; i < N; i++)
  {
    ans = gcd(ans, A[i]);
  }
  cout << ans << endl;

  return 0;
}