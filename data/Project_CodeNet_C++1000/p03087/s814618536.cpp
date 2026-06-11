#include "bits/stdc++.h"
using namespace std;

//31
typedef long long ll;

ll power(ll a , ll b) {
    ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans  * a;
		}
		a = a * a;
		b  /= 2;
	}
	return ans;
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	string s;
	cin >> s;
	int p = 0;
	for (int i = 0; i + 1 < n;) {
		v[i] = p;
		if (s[i] == 'A' && s[i + 1] == 'C') {
			p++;
			v[i + 1] = p;
			i += 2;
		}else {
		    i++;
		}
	}
	v[n - 1] = p;
	//for (int i = 0; i < n; ++i) {
		//cout << v[i] << " "<< i << endl;
	//}
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--,r--;
		//if(l == 0) {
		//	cout << v[r] << "--"<< endl;
		//}else {
			cout << v[r] - v[l] << endl; 
		//}
	}
}
