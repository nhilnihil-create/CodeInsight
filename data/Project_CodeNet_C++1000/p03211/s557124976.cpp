#include <bits/stdc++.h>
using namespace std;

#define sswap(x, y) { x+=y; y=x-y; x-=y; }
#define LSOne(S) ((S) & (-S))

#define EPS 1e-6
#define MOD 1000000007

#define fi first
#define se second
#define pb push_back
#define ende '\n'

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mset(x, y) memset(&x, (y), sizeof(x))

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
	string s;
	cin >> s;
	int m = 100000;
	for (int i = 0; i < s.size()-2; i++) {
		int v = s[i]*100+s[i+1]*10+s[i+2]-'0'*(111);
		if (abs(753-v) < m) m = abs(753-v);
	}
	cout << m << ende;
  return 0;
}
