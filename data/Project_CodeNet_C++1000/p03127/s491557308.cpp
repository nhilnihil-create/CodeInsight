#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
vector<ll> a(55), p(55);

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }

int main() {
  int n, a, b;
  cin >> n >> a;
  for (int i = 1; i < n; i++) {
    cin >> b;
    a = gcd(a, b);
  }
  cout << a;
  
  return 0;
}
