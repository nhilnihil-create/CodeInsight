#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, q;
string s;

int main(void){
	cin >> n >> q >> s;
	vector<lli> c(n);
	c[0] = c[1] = 0;
	for(int i = 1; i < n; i++){
		c[i] = c[i-1];
		if(s[i-1] == 'A' && s[i] == 'C') c[i]++;
	}
	rep(i, q){
		lli l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << c[r]-c[l] << endl;
	}
	return 0;
}
