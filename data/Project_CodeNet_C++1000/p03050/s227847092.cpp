#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

    priority_queue<ll> div;
    for (ll ii = 1; ii*ii <= N; ++ii){
        if (N % ii == 0){
            div.push(ii);
            if (N / ii != ii){
                div.push(N / ii);   //重複しないなら相方も追加
            }
        }
    }

    ll ans = 0;
    while (!div.empty()) {
    	ll tmp = div.top();
    	div.pop();

    	ll val = tmp - 1;
    	ll val2 = N / tmp;
    	if (val > val2){
    		ans += val;
    	} else {
    		break;
    	}
    }

	cout << ans << "\n";

	return 0;
}
