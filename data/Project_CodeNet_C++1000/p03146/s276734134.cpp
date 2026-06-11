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
	int s;
	cin >> s;
	set<int> conj;
	int i = 1;
	while (!conj.count(s)) {
		conj.insert(s);
		i++;
		s = s%2 ? s*3+1 : s/2;
	}
	cout << i << ende;
  return 0;
}
