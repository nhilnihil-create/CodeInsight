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

const string YES = "YES";
const string NO = "NO";

char charElse(char c1, char c2) {
  set<char> chars;
  chars.insert('a');
  chars.insert('b');
  chars.insert('c');

  chars.erase(c1);
  chars.erase(c2);
  return *chars.begin();
}

bool solve_(char c1, char c2, map<char, ll> cnt) {
  char c3 = charElse(c1, c2);

  while (true) {
    if (cnt[c1] == 0) {
      break;
    }
    cnt[c1]--;

    if (cnt[c2] == 0) {
      break;
    }
    cnt[c2]--;

    if (cnt[c3] == 0) {
      break;
    }
    cnt[c3]--;
  }

  if (cnt[c1] == 0 && cnt[c2] == 0 && cnt[c3] == 0) {
    return true;
  }
  return false;
}

void solve(std::string S) {
  map<char, ll> cnt;
  rep(i, S.size()) { cnt[S[i]]++; }

  bool ans = false;
  for (char c1 = 'a'; c1 <= 'c'; c1++) {
    for (char c2 = 'a'; c2 <= 'c'; c2++) {
      if (c1 == c2) {
        continue;
      }
      ans = ans || solve_(c1, c2, cnt);
    }
  }

  if (ans) {
    print(YES);
  } else {
    print(NO);
  }
}

int main() {
  std::string S;
  std::cin >> S;
  solve(S);
  return 0;
}
