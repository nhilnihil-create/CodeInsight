#include<bits/stdc++.h>
#define lli long long
const lli MOD = 998244353LL;
const int mxsz = 100055;
using namespace std;


int main(){
	ios::sync_with_stdio (false);
	int n;
	cin >> n;
	vector<int> l, r;
	l.push_back(0);
	r.push_back(0);
	for(int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		l.push_back(a);
		r.push_back(b);	
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	reverse(l.begin(), l.end());
	lli ans = 0;
	for(int i = 0 ; i <= n; i++){
		ans = max(ans, ans + (lli)l[i] - (lli)r[i]);
	}
	cout << 2LL * ans;
	return 0;
}