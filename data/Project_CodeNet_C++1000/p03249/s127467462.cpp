#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 100005;

void my_ass(bool p){
	if(!p){
		puts("-1");
		exit(0);
	}
}

int n, leaf_size[MAXN];
pi a[MAXN];
vector<int> gph[MAXN];

lint get_dist(int x, int d){
	lint ret = d;
	for(auto &i : gph[x]) ret += get_dist(i, d + 1);
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	fill(leaf_size + 1, leaf_size + n + 1, 1);
	for(int i=n; i>1; i--){
		lint nxt = a[i].first - n + 2 * leaf_size[i];
		int pos = lower_bound(a + 1, a + n + 1, pi(nxt, -1)) - a;
		if(a[pos].first == nxt && pos < i){
			gph[pos].push_back(i);
			leaf_size[pos] += leaf_size[i];
		}
		else my_ass(0);
	}
	my_ass(get_dist(1, 0) == a[1].first);
	for(int i=1; i<=n; i++){
		for(auto &j : gph[i]){
			if(i < j) printf("%d %d\n", a[i].second, a[j].second);
		}
	}
}
