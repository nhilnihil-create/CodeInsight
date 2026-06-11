#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int n, q;
string s;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> s >> q;
	while(q--){
		Int k; cin >> k;
		Int ans = 0;
		Int d = 0, m = 0, dm = 0;
		for(Int i=0; i<n; ++i){
			if(s[i] == 'D'){
				++d;
			}else if(s[i] == 'M'){
				++m;
				dm += d;
			}else if(s[i] == 'C'){
				ans += dm;
			}
			if(i-k+1 >= 0){
				if(s[i-k+1] == 'D'){
					--d;
					dm -= m;
				}else if(s[i-k+1] == 'M'){
					--m;
				}
			}
		}
		cout << ans << "\n";
	}
}