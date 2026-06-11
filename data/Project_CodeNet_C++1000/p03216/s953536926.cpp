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

void solve(long long N, std::string S, long long Q, std::vector<long long> k) {
  rep(q, Q) {
    ll kNum = k[q];
    ll dNum = 0;
    ll mNum = 0;
    ll cNum = 0;
    ll mcNum = 0;
    ll dmNum = 0;
    ll dmcNum = 0;

    rep(r, N) {
      ll l = r - kNum;
      if (l >= 0) {
        if (S[l] == 'D') {
          dNum--;
          dmNum -= mNum;
        } else if (S[l] == 'M') {
          mNum--;
          mcNum -= cNum;
        } else if (S[l] == 'C') {
          cNum--;
        }
      }

      if (S[r] == 'D') {
        dNum++;
      } else if (S[r] == 'M') {
        mNum++;
        dmNum += dNum;
      } else if (S[r] == 'C') {
        cNum++;
        mcNum += mNum;
        dmcNum += dmNum;
      }
    }
    print(dmcNum);
  }
}

int main() {
  long long N;
  scanf("%lld", &N);
  std::string S;
  std::cin >> S;
  long long Q;
  scanf("%lld", &Q);
  std::vector<long long> k(Q - 1 - 0 + 1);
  for (int i = 0; i < Q - 1 - 0 + 1; i++) {
    scanf("%lld", &k[i]);
  }
  solve(N, S, Q, std::move(k));
  return 0;
}
