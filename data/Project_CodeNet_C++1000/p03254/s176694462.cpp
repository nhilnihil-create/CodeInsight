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

	int n, x;
	cin>>n>>x;
	vector<int> a(n);
	for(auto &y : a){
		cin>>y;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(x < a[i])break;
		x -= a[i];
		ans++;
	}
	if(ans == n && x > 0)ans--;
	cout<<ans<<endl;

	return 0;
}