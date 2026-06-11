#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;

bool IS_PRIME[55556];
vector<int> PRIMES;
int MAX_N = 55556;

void init_prime() {
  rep(i, MAX_N) {
    IS_PRIME[i] = true;
  }

  for(int i = 2; i <= MAX_N; i++) {
    if(!IS_PRIME[i]) continue;
    PRIMES.push_back(i);

    for(int j = i * 2; j <= MAX_N; j += i) {
      IS_PRIME[j] = false;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  init_prime();

  int cnt = 0;

  rep(i, PRIMES.size()) {
    if(PRIMES[i] % 5 == 1) {
      cout << PRIMES[i];
      cnt++;
      if(cnt == N) {
        cout << endl;
        break;
      } else {
        cout << " ";
      }
    }
  }

  cout << endl;
}
