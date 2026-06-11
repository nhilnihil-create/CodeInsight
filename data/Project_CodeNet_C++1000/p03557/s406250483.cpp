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

	int n;
	cin>>n;
	vector<int> a(n), b(n), c(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}
	for(int i = 0; i < n; i++){
		cin>>c[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	vector<ll> cntb(n);
	for(int i = 0; i < n; i++){
		cntb[i] = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
		if(i)cntb[i] += cntb[i - 1];
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int ind = lower_bound(b.begin(), b.end(), c[i]) - b.begin(); ind--;
		if(ind >= 0)ans +=  cntb[ind];
	}
	cout<<ans<<endl;

	return 0;
}