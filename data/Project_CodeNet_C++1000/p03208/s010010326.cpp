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
	vector<int> h(n);
	for(auto &x : h){
		cin>>x;
	}
	sort(h.begin(), h.end());
	int ans = h[k - 1] - h[0];
	for(int i = k; i < n; i++){
		ans = min(ans, h[i] - h[i - k + 1]);
	}
	cout<<ans<<endl;

	return 0;
}