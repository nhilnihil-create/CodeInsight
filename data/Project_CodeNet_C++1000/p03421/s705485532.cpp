#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, a, b; cin >> n >> a >> b;
	if(a == 1){
		if(b == n){
			for(int i = n; i >= 1; i--) cout << i << " "; cout << endl;
		} else {
			cout << -1 << endl;
		}
	} else if(b == 1) {
		if(a == n){
			for(int i = 1; i <= n; i++) cout << i << " "; cout << endl;
		} else {
			cout << -1 << endl;
		}
	} else {
		if(a + b - 1 > n || 1ll * a * b < n) cout << -1 << endl;
		else {
			vector<vector<int> > bl;
			for(int i = 0; true; i++){
				vector<int> now;
				for(int j = 0; j < a; j++) if(i * a + j + 1 <= n) now.push_back(i * a + j + 1);
				bl.push_back(now);
				if(now.back() == n) break;
			}
			vector<vector<int> > rbl;
			int miss = b - bl.size();
			for(int i = bl.size() - 1; i >= 0; i--){
				while(bl[i].size() > 1 && miss){
					rbl.push_back({bl[i].back()});
					bl[i].pop_back();
					miss--;
				}
				rbl.push_back(bl[i]);
			}
			vector<int> ans;
			for(int i = 0; i < rbl.size(); i++){
				for(int v : rbl[i]) ans.push_back(v);
			}
			bool oka = true, okb = true;
			{
				vector<int> lis;
				for(int v : ans){
					int pt = lower_bound(lis.begin(), lis.end(), v) - lis.begin();
					if(pt == lis.size()) lis.push_back(v);
					else lis[pt] = v;
				}
				oka &= lis.size() == a;
			}
			{
				vector<int> lis;
				for(int v : ans){
					int pt = lower_bound(lis.begin(), lis.end(), -v) - lis.begin();
					if(pt == lis.size()) lis.push_back(-v);
					else lis[pt] = -v;
				}
				okb &= lis.size() == b;
			}
			if(ans.size() == n && oka && okb){
				for(int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
			} else {
				cout << -1 << endl;
			}
		}
	}
	return 0;
}
