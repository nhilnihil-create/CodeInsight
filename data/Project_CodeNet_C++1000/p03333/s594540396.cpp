#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

ll Solve(vector<ll> L, vector<ll> R) {
  int n = L.size();
  sort(L.rbegin(), L.rend());
  sort(R.begin(), R.end());
  ll x = 0;
  ll result = 0;
  for (int i = 0; i < n; ++i) {
    if (L[i] >= x) {
      result += L[i] - x;
      x = L[i];
    } else {
      break;
    }

    if (R[i] <= x) {
      result += x - R[i];
      x = R[i];
    } else {
      break;
    }
  }
  result += abs(x);
  return result;
}

int main()
{
  int n;
  cin >> n;
  vector<ll> L(n), R(n);
  for (int i = 0; i < n; ++i) {
    cin >> L[i] >> R[i];
  }

  ll result = Solve(L, R);
  for (int i = 0; i < n; ++i) {
    L[i] *= -1;
    R[i] *= -1;
  }
  swap(L, R);
  result = max(result, Solve(L, R));
  cout << result << endl;
  return 0;
}
