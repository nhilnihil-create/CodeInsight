#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << ((b - a) % 2 ? "Borys" : "Alice") << endl;
}