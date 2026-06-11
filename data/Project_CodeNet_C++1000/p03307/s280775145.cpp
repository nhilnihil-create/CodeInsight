#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  if (N % 2 == 0) {
    cout << N << "\n";
  }
  else {
    cout << 2 * N << "\n";
  }
}
