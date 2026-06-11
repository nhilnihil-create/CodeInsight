#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  vector<int> A(N+2);
  A.at(0) = 0; A.at(N+1) = 0;
  for (int i=1; i<N+1; i++) cin >> A.at(i);
  vector<int> B(N+1);
  ll sum = 0;
  for (int i=0; i<N+1; i++) {
    B.at(i) = A.at(i+1) - A.at(i);
    if (B.at(i) >= 0) sum += B.at(i);
    else sum -= B.at(i);
  }
  for (int i=1; i<N+1; i++) {
    ll ans;
    if (B.at(i-1) >= 0 && B.at(i) >= 0) ans = sum;
    else if (B.at(i-1) >= 0 && B.at(i) < 0) {
      if (B.at(i-1) >= -B.at(i)) ans = sum + 2*B.at(i);
      else ans = sum - 2*B.at(i-1);
    }
    else if (B.at(i-1) < 0 && B.at(i) >= 0) {
      if (-B.at(i-1) >= B.at(i)) ans = sum - 2*B.at(i);
      else ans = sum + 2*B.at(i-1);
    }
    else ans = sum;
    cout << ans << endl;
  }
}