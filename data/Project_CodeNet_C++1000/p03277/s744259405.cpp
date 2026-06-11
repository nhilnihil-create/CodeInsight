#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int BASE = 100000;

ll N; 
int a[100005], tree[200005], cum[100005];
vector<int> c1[200005], c2[200005];

int get_cum(int idx){
	int sum = 0;
	for(; idx; idx -= (idx & -idx))
		sum += tree[idx];
	return sum;
}

void add_val(int idx, int val, int TN){
	for(; idx <= TN; idx += (idx & -idx))
		tree[idx] += val;
}

ll count_low(int k){
	for(int i = 0; i <= 2 * BASE; i++)
		c1[i].clear(), c2[i].clear();

	ll sum = 0, cur = 0;
	for(int i = 1; i <= N; i++){
		c1[BASE + cur].push_back(i);
		c2[BASE + ((a[i] < k) ? --cur : ++cur)].push_back(i);
		add_val(i, 1, N);
	}

	for(int i = 0 ; i <= 2 * BASE; i++){
		if(!c1[i].size() && !c2[i].size()) continue;
		sort(c1[i].begin(), c1[i].end());
		sort(c2[i].begin(), c2[i].end());

		for(int r : c2[i])
			sum += get_cum(r);
		for(int l : c1[i])
			add_val(l, -1, N);

		ll leven = 0, lodd = 0;
		for(int ri = 0, li = 0; ri < c2[i].size(); ri++){
			while(li < c1[i].size() && c1[i][li] < c2[i][ri]){
				(c1[i][li++] & 1) ? lodd++ : leven++;
			}
			if(c2[i][ri] & 1) sum -= leven;
			else sum -= lodd;
		}
	}
	return sum;
}

int main()
{
	scanf("%lld", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);

	ll tot = N * (N - 1) / 2 + N;
	int l = 0, r = 1000000000, m, ans = -1;
	while(l <= r){
		m = (l + r) / 2;

		if(count_low(m) >= tot / 2 + 1){
			r = m - 1;
		}
		else ans = m, l = m + 1;
	}
	printf("%lld\n", ans);

	return 0;
}