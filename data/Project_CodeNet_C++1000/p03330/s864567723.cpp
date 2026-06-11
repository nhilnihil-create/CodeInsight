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
	int n, c;
	cin >> n >> c;
	vector<vector<int>> d(c, vector<int>(c));
	rep(i, c)rep(j, c){
		cin >> d.at(i).at(j);
	}
	vector<map<int, int>> mv(3);
	rep(i, n)rep(j, n){
		int ii = i+1, jj = j+1;
		int in;
		cin >> in;
		in--;
		mv.at((ii+jj)%3)[in]++;
	}
	ll ans = 1e18;
	rep(i, c){
		ll add0 = 0;
		for(auto p : mv.at(0)){
			add0 += d.at(p.first).at(i) * p.second;
		}
		rep(j, c){
			ll add1 = 0;
			if(j == i) continue;
			for(auto p1 : mv.at(1)){
				add1 += d.at(p1.first).at(j) * p1.second;
			}
			rep(k, c){
				ll add2 = 0;
				if(i == k || j == k) continue;
				for(auto p2 : mv.at(2)){
					add2 += d.at(p2.first).at(k) * p2.second;
				}
				ans = min(ans, add0+add1+add2);
			}
		}
	}
	cout << ans << endl;
	return 0;
}