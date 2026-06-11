#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> a(m);
	rep(i, m) cin >> a[i];

	vector<int> b{0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	vector<int> dp(n+1, -1);
	dp[0] = 0;
	for(int i = 0; i <= n; i++){
		if(dp[i] == -1) continue;
		rep(j, m){
			int x = b[a[j]];
			if(i + x <= n) chmax(dp[i + x], dp[i] + 1);
		}
	}

	sort(a.begin(), a.end(), greater<int>());

	int p = n;
	string ans;
	while(p > 0){
		rep(j, m){
			int x = b[a[j]];
			if(p - x >= 0 && dp[p - x] == dp[p] - 1){
				p -= x;
				ans.push_back('0' + a[j]);
				break;
			}
		}
	}

	cout << ans << endl;
}
