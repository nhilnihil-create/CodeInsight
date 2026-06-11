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
	vector<int> a(n);
	for(auto &x : a){
		cin>>x;
	}
	int ans = 1e9;
	for(int i = 0; i + k <= n; i++){
		ans = min(ans, abs(a[i]) + a[i + k - 1] - a[i]);
		ans = min(ans, abs(a[i + k - 1]) + a[i + k - 1] - a[i]);
	}
	cout<<ans<<endl;

	return 0;
}