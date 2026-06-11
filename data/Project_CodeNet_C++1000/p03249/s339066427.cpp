#include <algorithm>
#include <iostream>
#include <cstdio>
#define mp make_pair
#define fi first
#define se second
using namespace std;
pair <long long, int> a[1000006];
pair <int, int> edge[1000006];
int sze[1000006];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		scanf("%lld", &a[i].fi);
		a[i].se = i;
	}
	sort(a + 1, a + 1 + n);
	int m = 0;
	long long sum = 0;
	for (int i = n; i >= 2; -- i){
		sum += ++ sze[i];
		long long d = a[i].fi - n + 2 * sze[i];
		int index = lower_bound(a + 1, a + 1 + n, mp(d, 0)) - a;
		if (a[index].fi != d || index >= i){
			cout << -1 << endl;
			return 0;
		}
		edge[++ m] = mp(a[index].se, a[i].se);
		sze[index] += sze[i];
	}
	if (a[1].fi != sum){
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= m; ++ i)
		printf("%d %d\n", edge[i].fi, edge[i].se);
	return 0;
}
/*
7
9
14
12
17
10
13
18
*/
