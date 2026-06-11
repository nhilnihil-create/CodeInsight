#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int d;
  cin >> d;

  if (d == 25) {
    cout << "Christmas";
  } else if (d == 24) {
    cout << "Christmas Eve";
  } else if (d == 23) {
    cout << "Christmas Eve Eve";
  } else {
    cout << "Christmas Eve Eve Eve";
  }
}