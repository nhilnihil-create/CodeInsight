#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using vpi = vector<pi>;
const int maxn = 1<<19, mod = 998244353;
int n;
pi a[maxn];
pi merge(pi a, pi b) {
	if(b.first>a.first) swap(a, b);
	if(b.first>a.second) a.second = b.first;
	return a;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < 1<<n; i++) cin >> a[i].first;
	for(int j = 0; j < n; j++)
	for(int i = 0; i < 1<<n; i++)
		if(i&(1<<j))
			a[i] = merge(a[i], a[i^(1<<j)]);
	int lst = 0;
	for(int i = 1; i < 1 << n; i++) {
		lst = max(lst, a[i].first + a[i].second);
		cout << lst << "\n";
	}
}
