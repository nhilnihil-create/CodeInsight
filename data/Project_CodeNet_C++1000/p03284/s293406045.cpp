#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, K;
  cin >> N >> K;
  if (N % K == 0) {
    cout << 0 << "\n";
  }
  else {
    cout << 1 << "\n";
  }
}
