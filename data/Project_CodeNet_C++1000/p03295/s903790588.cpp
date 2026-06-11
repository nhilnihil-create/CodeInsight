#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> ba(m);
	rep(i, m) {
		int ai, bi;
		cin >> ai >> bi;
		ai--; bi--;
		ba[i] = { bi,ai };
	}
	sort(ba.begin(), ba.end());
	int now = -1;
	int ans = 0;
	rep(i, m) {
		if (ba[i].second > now) {
			now = ba[i].first-1;
			ans++;
		}
	}
	cout << ans << endl;
}
