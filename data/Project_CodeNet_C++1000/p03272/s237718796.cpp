#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()


int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, i; cin >> n >> i;
	cout << n - (i - 1) << '\n';
	return 0;
}
