#include <iostream>
#include <cstdio>
#include <vector>
#define N 100005
using namespace std;

typedef long long ll;
ll n, m, v[N], c[3];
vector<ll> gr[N];

bool f(ll p, ll q) {
	ll i;
    if (v[p]) return v[p] == q;
    v[p] = q;
    for (i = 0; i < gr[p].size(); i++) {
		if (!f(gr[p][i], 3 - q)) return 0;
    }
    return 1;
}

int main()
{
	ll i, t1, t2;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		scanf("%lld %lld", &t1, &t2);
		gr[t1].push_back(t2);
		gr[t2].push_back(t1);
	}
    if (f(1, 1)) {
		for (i = 1; i <= n; i++) c[v[i]]++;
		cout << c[1] * c[2] - m << endl;
    } else {
		cout << n * (n - 1) / 2 - m << endl;
    }
    return 0;
}