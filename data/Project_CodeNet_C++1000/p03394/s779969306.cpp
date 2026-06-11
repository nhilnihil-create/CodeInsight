#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, Y) for (int(X) = 0; (X) < (Y); ++(X))
#define rrep(X, Y) for (int(X) = (Y)-1; (X) >= 0; --(X))
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve(long long N) {
  vl ans;

  if (N == 3) {
    ans.push_back(2);
    ans.push_back(5);
    ans.push_back(63);
  } else if (N == 4) {
    ans.push_back(2);
    ans.push_back(5);
    ans.push_back(20);
    ans.push_back(63);
  } else if (N == 5) {
    ans.push_back(2);
    ans.push_back(5);
    ans.push_back(20);
    ans.push_back(30);
    ans.push_back(63);
  } else {
    ll cnt = 0;
    ll i = 0;
    ll m = 2;
    while (cnt < N) {
      ans.push_back(6 * i + m);
      cnt++;

      if (cnt == N) {
        break;
      }

      if (m == 0) {
        m = 2;
      } else if (m == 2) {
        m = 3;
      } else if (m == 3) {
        m = 4;
      } else if (m == 4) {
        i++;
        m = 0;
      }
    }

    ll sum = 0;
    rep(n, N) { sum += ans[n]; }
    ll rest = sum % 6;
    if (rest == 2) {
      ans[4] = ++i * 6;
    }
    if (rest == 3) {
      ans[5] = ++i * 6;
    }
    if (rest == 5) {
      if (m == 4) {
        ans[5] = ++i * 6 + 4;
      } else {
        ans[5] = i * 6 + 4;
      }
    }
  }

  rep(n, N) {
    cout << ans[n];
    if (n != N - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  long long N;
  scanf("%lld", &N);
  solve(N);
  return 0;
}
