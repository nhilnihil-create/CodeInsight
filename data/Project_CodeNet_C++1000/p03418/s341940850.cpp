#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#define rep(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long ll;
const ll LLINF = 9223372036854775807;
const int MOD = 1000000007;

int main() {
  ll N, K; cin >> N >> K;

  ll result = 0;
  if (K==0) result = N*N;
  else for(int i=K+1; i<=N; i++){
    ll d = N/i, m = N%i;
    result += (i-K)*d;
    if (m>=K) result += m-K+1;
  }
  cout << result << endl;
  return 0;
}