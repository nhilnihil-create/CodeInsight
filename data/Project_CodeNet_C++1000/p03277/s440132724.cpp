#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
const int N = 1e5 + 1;

int a[maxn], par[maxn], fen[maxn];
int n;

int get(int x){
	int ret = 0;
	for (x += N; x; x -= x & -x)
		ret += fen[x];
	return ret;
}

void add(int x, int val){
	for (x += N; x < maxn; x += x & -x)
		fen[x] += val;
}

ll check(int x){
	for (int i = 1; i <= n; i++)
		par[i] = (a[i] < x ? 1 : -1);
	for (int i = 1; i <= n; i++)
		par[i] += par[i - 1];

	add(par[0], +1);
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += get(par[i] - 1);
		add(par[i], +1);
	}
	for (int i = 0; i <= n; i++)
		add(par[i], -1);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll tot = 1ll * n * (n + 1) / 2;
	int lo = 1, hi = 1000 * 1000 * 1000 + 1;
	while (hi - lo > 1){
		int mid = (lo + hi) / 2;
		if (check(mid) > tot / 2)
			hi = mid;
		else
			lo = mid;
	}
	cout << lo << endl;
}
