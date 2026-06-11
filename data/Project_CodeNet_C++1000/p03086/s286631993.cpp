#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
  string S;
  cin >> S;

  ll ans = 0;
  ll count = 0;
  rep(i, S.size()) {
    if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
      count++;
    }
    else {
      ans = ans > count ? ans : count;
      count = 0;
    }
  }
  ans = ans > count ? ans : count;
  cout << ans << endl;
  return 0;
}

