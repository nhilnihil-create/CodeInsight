#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int k;
	cin >> k;
	vector<ll> a(k);
	rep(i,k)cin >> a[i];
	reverse(ALL(a));
	ll l  = 2, r = 2;
	for(int i=0;i<k;i++){
		l = (l + a[i] - 1 )/a[i] * a[i];
		r = ((r/a[i]) + 1) * a[i] - 1;
		if(l>r){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << l << " " << r << endl;
}