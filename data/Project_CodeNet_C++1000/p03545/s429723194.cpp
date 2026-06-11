#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define DD long double

#define M 1000000007
#define INF 1e18

void setIO(string s = "") { 
  cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if (s.size()) s += ".in", freopen(s.c_str(), "r", stdin);
}

int tt = 1;
void solve() {
  int arr[4];
  char cc;
  for (int i = 0; i < 4; i++) cin >> cc, arr[i] = atoi(&cc);
  int a = arr[0], b = arr[1], c = arr[2], d = arr[3];
  if (a-b-c-d==7) cout << a << "-" << b << "-" << c << "-" << d << "=7"; 
  else if (a-b-c+d ==7) cout << a << "-" << b << "-" << c << "+" << d << "=7"; 
  else if (a-b+c-d ==7) cout << a << "-" << b << "+" << c << "-" << d << "=7"; 
  else if (a-b+c+d ==7) cout << a << "-" << b << "+" << c << "+" << d << "=7";
  else if (a+b-c-d ==7) cout << a << "+" << b << "-" << c << "-" << d << "=7";
  else if (a+b-c+d ==7) cout << a << "+" << b << "-" << c << "+" << d << "=7";
  else if (a+b+c-d ==7) cout << a << "+" << b << "+" << c << "-" << d << "=7";
  else if (a+b+c+d ==7) cout << a << "+" << b << "+" << c << "+" << d << "=7";
}

int main() {
 setIO();
  while (tt--) {
    solve();
  }
  return 0;
}