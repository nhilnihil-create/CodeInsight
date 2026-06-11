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
	string s;
	cin >> s;
	int fr = 0, re = s.size()-1;
	int ans = 0;
	while(1){
		if(fr >= re) break;
		char f = s[fr], r = s[re];
		if(f != r){
			ans++;
			if(f != 'x' && r != 'x'){
				ans = -1;
				break;
			}else if(f != 'x'){
				re--;
			}else{
				fr++;
			}
		}else{
			fr++;
			re--;
		}
	}
	cout << ans << endl;
	return 0;
}