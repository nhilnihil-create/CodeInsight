#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define ll long long
ll INF = 10001000100;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	vector<int> c(n);
	rep(i,n) cin >> v[i];
	rep(i,n) cin >> c[i];

	 bitset<20> sum;
	 int ans = 0;
	 rep(i,n) {
	 		if(v[i]>c[i]) ans+=v[i]-c[i];	 	
	 }
	 cout << ans << endl;
}