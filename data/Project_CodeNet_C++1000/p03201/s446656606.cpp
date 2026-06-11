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
	map<int, int> m;
	rep(i, n){
		int in;
		cin >> in;
		m[in]++;;
	}
	int ans = 0;
	rrepit(ritr, m){
		int p1 = ritr->first;
		int p1_sec = ritr->second;
		int p2 = pow(2, (int)log2(p1) + 1) - p1;
		if(p1 == p2){
			int add = p1_sec / 2;
			ans += add;
			m[p1] -= add;
		}else if(m.count(p2) == 1){
			int p2_sec = m[p2];
			int add = min(p1_sec, p2_sec);
			ans += add;
			m[p1] -= add;
			m[p2] -= add;
		}
	}
	cout << ans << endl;
	return 0;
}