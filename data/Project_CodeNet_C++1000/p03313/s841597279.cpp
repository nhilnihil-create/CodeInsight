#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 18);
int n, a[N];

vector<int> sub[N], ans(N);

signed main(){
	cin >> n;
	for(int i = 0; i < (1 << n); ++i) cin >> a[i], sub[i].push_back(a[i]);
	for(int j = 0; j < n; ++j){	
		for(int i = 0; i < (1 << n); ++i){
			if(!(i & (1 << j))){
				for(auto v : sub[i]) sub[i | (1 << j)].push_back(v);
				sort(sub[i | (1 << j)].rbegin(), sub[i | (1 << j)].rend());
				while(sub[i | (1 << j)].size() > 2) sub[i | (1 << j)].pop_back();
			}
		}
	}
	for(int i = 1; i < (1 << n); ++i){
		ans[i] = max({ans[i], ans[i - 1], sub[i][0] + sub[i][1]});
	}
	for(int i = 1; i < (1 << n); ++i) cout << ans[i] << '\n';
	
}