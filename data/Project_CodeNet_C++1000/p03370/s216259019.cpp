#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(vs) vs.begin(), vs.end()
using ll = long long;
using ii = pair<ll, ll>;

int32_t main(){
	ios::sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	vector<int> vs(n);
	int k = 1e9;
	for(auto &w:vs) cin >> w, x-=w, k = min(k, w);
       	int ans = n + x/k;
	cout << ans << endl;	

}