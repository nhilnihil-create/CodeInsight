#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a, b, k;
	cin >> a >> b >> k;
	int n = __gcd(a, b);
	vector<int> as(0);
	for(int i=1; i*i<=n; i++){
		if(n%i == 0){
			as.push_back(i);
			if(i != n/i) as.push_back(n/i);/*
			cout << i << ' ';
			if(i != n/i) cout << n/i;
			cout << endl;*/
		}
	}
	sort(as.begin(), as.end());
	reverse(as.begin(), as.end());
	cout << as.at(k-1) << endl;
	return 0;
}