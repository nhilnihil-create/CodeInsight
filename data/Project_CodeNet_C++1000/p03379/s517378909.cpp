#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> x(n);
	vector<lli> y(n);
	rep(i, n){
		cin >> x[i];
		y[i] = x[i];
	}
	sort(y.begin(), y.end());
	rep(i, n){
		if(x[i] <= y[n/2-1]) cout << y[n/2] << endl;
		else cout << y[n/2-1] << endl;
	}
	return 0;
}
