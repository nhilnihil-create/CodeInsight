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
	string s;
	cin >> s;
	vector<int> wh(n, 0);
	rrep(i, n){
		if(i != n-1) wh.at(i) = wh.at(i+1);
		if(s[i] == '.') wh.at(i)++;
	}
	vector<int> bk(n, 0);
	rep(i, n){
		if(i != 0) bk.at(i) = bk.at(i-1);
		if(s[i] == '#') bk.at(i)++;
	}
	int ans = n;
	rep(i, n + 1){
		int add = 0;
		if(i < n) add += wh.at(i);
		if(i != 0) add += bk.at(i-1);
		ans = min(ans, add);
	}
	cout << ans << endl;
	return 0;
}