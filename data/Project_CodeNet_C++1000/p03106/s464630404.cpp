#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  stack<int> d;
  for(int i = 1; i <= 100; i++) {
    if(a % i == 0 && b % i == 0) {
      d.push(i);
    }
  }
  for(int i = 0; i < k - 1; i++) {
    d.pop();
  }
  cout << d.top() << endl;
}