#include <bits/stdc++.h>
using namespace std;
#define SORT(a) sort((a).begin(), (a).end())
#define RSORT(a) reverse((a).begin(), (a).end())
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const long long INF = 1LL << 60;

int main() {
  ll n, m;
  cin >> n >> m;
  cout << abs(n - 2) * abs(m - 2) << endl;
}