#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N, M;
	cin >> N >> M;
	priority_queue<ll, vector<ll>, greater<ll> > Q;

	rep(i, N) {
		ll a;
		cin >> a;
		Q.push(a);
	}

	vector<pair<ll, ll> > CB(M);
	rep(i, M) {
		cin >> CB[i].second >> CB[i].first;
	}

	sort(CB.rbegin(), CB.rend());


	rep(i, M) {
		rep(j, CB[i].second) {
			if(Q.top() < CB[i].first) {
				ll tmp = Q.top();
				Q.pop();
				Q.push(CB[i].first);
			} else {
				break;
			}
		}
	}

	ll ans = 0;
	while(!Q.empty()) {
		ans += Q.top();
		Q.pop();
	}
	cout << ans << endl;
}
