#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  s[k-1] = tolower(s[k-1]);
  rep(i, n) cout <<s[i];
  cout << endl;
}