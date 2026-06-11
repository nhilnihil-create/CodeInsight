#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

int main() {
  
  int N;
  cin >> N;
  vector<ll> count(26, 0);

  rep(i,N) {
    string S;
    cin >> S;
    count[S[0] - 'A']++;
  }

  string march = "MARCH";
  ll ans = 0;
  for (int i = 0; i < 5; i++) for (int j = i + 1; j < 5; j++) for (int k = j + 1; k < 5; k++) {
    ans += count[march[i] - 'A'] * count[march[j] - 'A'] * count[march[k] - 'A'];
  }

  cout << ans << endl;

  return 0;
}