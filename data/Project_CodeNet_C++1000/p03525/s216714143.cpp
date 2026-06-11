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
	vector<int> d(n);
	rep(snip_i, n) cin >> d.at(snip_i);
	sort(d.begin(), d.end());
	vector<vector<int>> time(24, vector<int>());
	rep(i, n){
		int add = d.at(i);
		time.at(add).push_back(i);
	}
	bool flag = false;
	int bf = 0, ans = 25;
	rep(i, 24){
		int comp = -1;
		int s = time.at(i).size();
		if(i == 0 && s != 0){
			cout << 0 << endl;
			return 0;
		}
		if(s == 0)continue;
		else if(s == 1){
			if(i < 12){
				if(flag == true){
					int tr = 24 - i;
					time.at(tr).push_back(time.at(i).at(0));
					flag = false;
				}else{
					comp = i;
					flag = true;
				}
			}else{
				comp = i;
			}
		}else if(s == 2){
			if(i >= 12){
				cout << 0 << endl;
				return 0;
			}
			comp = i;
			int tr = 24 - i;
			time.at(tr).push_back(time.at(i).at(0));
		}else{
			cout << 0 << endl;
			return 0;
		}
		if(comp != -1){
			int diff = comp - bf;
			ans = min(ans, diff);
			bf = comp;
		}
	}
	cout << ans << endl;

	return 0;
}