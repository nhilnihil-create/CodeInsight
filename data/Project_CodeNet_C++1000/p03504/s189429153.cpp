#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;
static long long INF = (1LL<<62);
using LLPair = pair<LL, LL>;

const LL MAXT = 100000;

int contain(vector<pair<LL, LL>> &v, LL t){
	if(v.size() == 0) return 0;

	int ret = 0;
	pair<LL, LL> p = make_pair(t, t);
	LL l1 = -1, r1 = -1, l0 = -1, r0 = -1;
	auto itr = lower_bound(v.begin(), v.end(), p);
	if(itr == v.end()){
		itr--;
	}
	l1 = itr->first;
	r1 = itr->second;
	if(t >= l1 && t <= r1){
		ret = 1;
	}
	if(t < l1){
		if(itr == v.begin()){
			ret = 0;
		}
		else{
			itr--;
			l0 = itr->first;
			r0 = itr->second;
			if(l0 <= t && t <= r0){
				ret = 1;
			}
			else{
				ret = 0;
			}
		}
	}
	return ret;
}

int main(int argc, char* argv[]){

	LL N, C; cin >> N >> C;
	LL S = MAXT, T = 0;
	vector<vector<pair<LL, LL>>> V(C);
	map<LL, int> CP; 
	for(int i=0; i<N; i++){
		LL s, t, c; cin >> s >> t >> c;
		c--;
		V[c].push_back(make_pair(s, t));
		if(S > s) S = s;
		if(T < t) T = t;
		if(CP.count(s) == 0) CP[s] = 1;
		if(CP.count(t) == 0) CP[t] = 1;
	}
	for(int c=0; c<C; c++){
		sort(V[c].begin(), V[c].end());
	}
	int ans = 0;
	for(auto itr = CP.begin(); itr != CP.end(); itr++){
		LL t = itr->first;
		int rec = 0;
		for(int c=0; c<C; c++){
			int r  = contain(V[c], t);
			rec += r;
		}
		if(ans < rec) ans = rec;
	}
	printf("%d\n", ans);
	return 0;
}