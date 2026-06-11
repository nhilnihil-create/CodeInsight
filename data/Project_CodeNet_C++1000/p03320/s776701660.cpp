#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

const int  MAX = (int)1e15;

double snuke(int n) {
	int m = n;
	int k = 0;
	while(m > 0) {
		k += m % 10;
		m /= 10;
	}
	return n / (double) k; 
}

double mn;
vector<int> v;

void dfs(int n, int d) {
	if(d == 0) {
		if(n == 0) return;
		v.push_back(n);
		mn = min(mn, snuke(n));
		return;
	}
	for(int i = 9; i >= 0; --i) {
		int m = n + (i - 9) * d;
		double s = snuke(m);
		if(s > mn) return;
		dfs(m, d / 10);
	}
}

signed main(){
	int K;
	cin >> K;

	mn = MAX;
	dfs(MAX - 1, MAX / 10);
	reverse(ALL(v));
	for(int i = 0; i < K; ++i) {
		cout << v[i] << endl;
	}
	return 0;
}
