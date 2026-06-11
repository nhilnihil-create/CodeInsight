#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  int maxm = -1;
  int sum = 0;
  rep(i, n) {
    int l;
    cin >> l;
    sum += l;
    maxm = max(maxm, l);
  }
  int ans = sum - maxm;
  if(maxm < ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}