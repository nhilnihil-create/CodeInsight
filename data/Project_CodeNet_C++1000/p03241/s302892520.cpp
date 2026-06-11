#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <int>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;

bool comp(pair <int,int> &p1,pair <int,int> &p2){
	return p1.first > p2.first;
}

void solve(){
	int n,m;
	cin >> n >> m;
	int ans = 1;
	vector <pair <int,int>> factors;
	for(int i = 1;i * i <= m;++i){
		if(m % i == 0) factors.push_back({m / i,i}), factors.push_back({i,m / i});
	}
	sort(factors.begin(),factors.end(),comp);
	for(int i = 0;i < factors.size();++i){
		if(factors[i].second >= n){
			cout << factors[i].first << newl;
			return;
		}
	}

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
