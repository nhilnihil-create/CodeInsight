#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll N,X;
ll x[200005];
ll sum[200005];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> X;

	ll ans = LLONG_MAX;

	for (ll i = 1;i <= N;i++){
		cin >> x[i];
		sum[i] = sum[i-1]+x[i];	
	}

	for (ll i = 1;i <= N;i++){
		ll cost = (i+N)*X;
		ll now = N;
		bool flag = false;
		for (ll j = 0;j < N/i;j++){
			if(j == 0){
				cost += (sum[now]-sum[now - i]) * 5;
				now -= i;
			}else{
				ll a = sum[now] - sum[now-i];
				ll b = 5+2*(j-1);
				if(LLONG_MAX/a< b) flag = true;
				else if(LLONG_MAX-cost < a*b)flag = true;
				cost += a * b;
				now -= i;
			}
		}
		if(sum[now] != 0 && LLONG_MAX/sum[now] < 5+2*(N/i - 1)) flag = true;
		else if(LLONG_MAX-cost < sum[now] * 5+2*(N/i - 1)) flag = true;
		cost += sum[now] * (5+2*(N/i - 1));
		if(!flag)ans = min(cost,ans);
	}

	cout << ans << endl;

	return 0;

}

