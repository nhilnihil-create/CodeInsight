#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  int a[N]; rep(i,N) cin >> a[i];

  int result = 0, count = 0;
  rep(i,N) {
    if (i==0||a[i]==a[i-1]) count++;
    else {
      result += count/2;
      count = 1;
    }
  }
  result += count/2;
  cout << result << endl;
  return 0;
}