#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	int ans = 0;
	for(int l = 0; l < n; l++){
		for(int r = 0; r + l <= n; r++){
			if(l + r > k)break;
			vector<int> vec;
			for(int i = 0; i < l; i++){
				vec.push_back(v[i]);
			}
			for(int i = 0; i < r; i++){
				vec.push_back(v[n - 1 - i]);
			}
			sort(vec.rbegin(), vec.rend());
			int cur = accumulate(vec.begin(), vec.end(), 0);
			int mx = k - l - r;
			while(mx--){
				if(vec.empty() || vec.back() >= 0)break;
				cur -= vec.back(); vec.pop_back();
			}
			ans = max(ans, cur);
		}
	}
	cout<<ans<<'\n';

	return 0;
}