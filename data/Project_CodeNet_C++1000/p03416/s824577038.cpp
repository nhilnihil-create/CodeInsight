#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;

  for (int i = a; i <= b; i++) {
    int first = i % 10;
    int fifth = i / 10000 % 10;
    int second = i / 10 % 10;
    int fourth = i / 1000 % 10;
    if (first == fifth && second == fourth) ++ans;
  }
  cout << ans << endl;

  return 0;
}