#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;

int main() {
	ll n,k;
	cin >> n >> k;

	

	vector<pair<ll,int>> sushi(n);
	
	
	for (int i = 0; i < n;i++) {
		int t, d;
		cin >> t >> d;
		t--;
		sushi[i] = make_pair(d, t);
	}
	
	vector<int> cnt_Ate(n);

	sort(sushi.begin(), sushi.end());

	vector<ll> sum_d(n+1);
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	ll s = 0;
	for (int i = n - 1; i >= n - k;i--) {
		s += sushi[i].first;
		if (cnt_Ate[sushi[i].second] > 0) {
			pq.push(sushi[i]);
		}
		cnt_Ate[sushi[i].second]++;
		
	}

	int c = 0;
	for (int i = 0; i < n;i++) {
		if (cnt_Ate[i] > 0) {
			c++;
		}
	}
	

	sum_d[c] = s;
	
	int p = n - k - 1;
	for (int i = c + 1; i <= n;i++) {
		
		while(p >=0 &&cnt_Ate[sushi[p].second] != 0 ) {
			p--;
			
		}
		
		if (p == -1) {
			break;
		}
		if (pq.empty()) {
			break;
		}
		cnt_Ate[sushi[p].second]++;
		sum_d[i] = sum_d[i - 1] + sushi[p].first - pq.top().first;
		
		pq.pop();

	}

	ll ans = 0;
	for (ll i = 1; i <=n; i++) {
		if (sum_d[i] > 0) {
			ans = max(i*i + sum_d[i], ans);
		}
	}
	
	cout << ans << endl;
}
