#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;

int n, q, k, a[MAXN];
vector<pi> crd;

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		while(x < MAXN){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit;

int sum = 0;

set<pi> s;

void rem_intv(pi s){
	int S = bit.query(s.second) - bit.query(s.first - 1);
	if(s.second - s.first + 1 >= k) sum -= min(S, s.second - s.first + 2 - k);
}

void add_intv(pi s){
	int S = bit.query(s.second) - bit.query(s.first - 1);
	if(s.second - s.first + 1 >= k) sum += min(S, s.second - s.first + 2 - k);
}

int main(){
	cin >> n >> k >> q;
	for(int i=0; i<n; i++){
		cin >> a[i];
		crd.emplace_back(a[i], i + 1);
	}
	sort(crd.rbegin(), crd.rend());
	int ret = 1e9;
	int e = 0;
	for(int i=0; i<crd.size(); i++){
		while(e < crd.size() && sum < q){
			bit.add(crd[e].second, 1);
			int st = crd[e].second, ed = crd[e].second;
			auto l = s.lower_bound(pi(crd[e].second, crd[e].second));
			if(l != s.end() && l->first == crd[e].second + 1){
				ed = l->second;
				rem_intv(*l);
				l = s.erase(l);
			}
			if(l != s.begin() && prev(l)->second == crd[e].second - 1){
				st = prev(l)->first;
				rem_intv(*prev(l));
				s.erase(prev(l));
			}
			add_intv(pi(st, ed));
			s.insert(pi(st, ed));
			e++;
		}
		if(sum >= q) ret = min(ret, crd[i].first - crd[e - 1].first);
		auto l = --s.upper_bound(pi(crd[i].second + 1, -1));
		rem_intv(*l);
		bit.add(crd[i].second, -1);
		add_intv(*l);
	}
	cout << ret << endl;
}
