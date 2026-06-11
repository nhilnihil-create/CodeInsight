#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<tuple<int, int, int>> c(n);
	rep(i, n){
		int a, b;
		cin >> a >> b;
		c.at(i) = make_tuple(a+b, a, b);
	}
	sort(c.rbegin(), c.rend());
	ll ta = 0, ao = 0;
	rep(i, n){
		if(i % 2 == 0) ta += get<1>(c.at(i));
		else ao += get<2>(c.at(i));
	}
	cout << ta - ao << endl;
	return 0;
}