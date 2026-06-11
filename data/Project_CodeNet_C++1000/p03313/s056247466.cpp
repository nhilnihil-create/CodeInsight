	#include <bits/stdc++.h>
	#define mx 300005
	using namespace std;

	int a[mx], n;
	vector<vector<bool> > vis(mx, vector<bool> (20, false));
	vector<vector<pair<int,int> > > memo(mx, vector<pair<int, int> > (20, {0, 0}));

	void dp(int num, int pos) {
		if(pos == 0) {
			memo[num][0].first = a[num];
			vis[num][0] = true;
			return;
		}
		if(vis[num][pos]) return;
 		vector<int> cons;
		dp(num, pos-1);
		cons.push_back(memo[num][pos-1].first);
		cons.push_back(memo[num][pos-1].second);
		if(num & (1<<(pos-1))) {
			dp(num ^ (1<<(pos-1)), pos-1);
			cons.push_back(memo[num ^ (1<<(pos-1))][pos-1].first);
			cons.push_back(memo[num ^ (1<<(pos-1))][pos-1].second);
		}
		sort(cons.begin(), cons.end(), greater<int>());
		memo[num][pos].first = cons[0];
		memo[num][pos].second = cons[1];
		vis[num][pos] = true;
	}

	int main() {
		ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	    cout.tie(NULL);

		cin >> n;
		for(int i = 0; i < (1<<n); ++i) {
			cin >> a[i];
			
		}
		for(int i = (1<<n) - 1; i >= 0; --i) {
			if(!vis[i][n]) {
				dp(i, n);
			}
		}
		int mxv = 0;
		for(int i = 1; i < 1<<n; ++i) {
			mxv = max(memo[i][n].first + memo[i][n].second, mxv);
			cout << mxv << "\n";	
		}
		return 0;
	}