#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>

#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int INF = pow(2,29);
const int MOD = 1000000007;

const int N_MAX = pow(10,6)+1;
vector<bool> isp(N_MAX, true);

void sieve() {
  isp[0] = false;
  isp[1] = false;
  for (int i=2; pow(i,2)<=N_MAX; i++) {
    if (isp[i]) for(int j=2; i*j<=N_MAX; j++) isp[i*j] = false;
  }
}

int main() {
  ll N, P; cin >> N >> P;

  ll result = 1;
  if (N==1) result = P;
  else {
    sieve();
    ll i=2;
    while (i*i<=P) {
      ll count = 0;
      while (P%i==0) {
        P /= i;
        count++;
      }
      result *= pow(i, count/N);
      i++;
    }
  }
  cout << result << endl;
  return 0;
}