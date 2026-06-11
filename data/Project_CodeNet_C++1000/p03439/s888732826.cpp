#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"

#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << endl; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}

#line 2 "tmp.cpp"

// おしまい:-1, 男:0, 女:1
int query(int i) {
  cout << i << endl;
  string s;
  cin >> s;
  if (s == "Vacant") {
    return -1;
  } else if (s == "Male") {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  int n;
  cin >> n;
  int init = query(0);
  if (init == -1) {
    return 0;
  }

  int rightVal = query(n / 2);
  if (rightVal == -1)
    return 0;
  int leftVal = query(n / 2 + 1);
  if (leftVal == -1)
    return 0;

  int right, left;
  if ((n / 2 % 2 == 1 && init == rightVal) || (n / 2 % 2 == 0 && init != rightVal)) {
    leftVal = init;
    left = 0;
    right = n / 2;
  } else {
    rightVal = init;
    left = n / 2 + 1;
    right = n;
  }

  while (abs(right - left) > 1) {
    int mid = ((right + left) / 2);
    int midVal = query(mid % n);
    if (midVal == -1)
      return 0;
    // 辻褄が合うときは相手
    if (((right - mid) % 2 == 0 && midVal == rightVal) || ((right - mid) % 2 == 1 && midVal != rightVal)) {
      right = mid;
      rightVal = midVal;
    } else {
      left = mid;
      leftVal = midVal;
    }
  }
  int tmp = query(left % n);
  if (tmp != -1) {
    query(right % n);
  }

  return 0;
}
