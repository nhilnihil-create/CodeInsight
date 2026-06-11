#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k, sum = 0;
    cin >> n;
    vector<ll> v(n + 2), t(n + 2);
    t[0] = 0;
    for(i = 1; i <= n; i++) {
        cin >> t[i];
        t[i] *= 2;
        sum += t[i];
		t[i]=sum;
    }
    v[0] = 0;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] *= 2;
    }
    double train[200100]; // train[time]
    for(i = 0; i <= sum; i++)
        train[i] = 1000.0;
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= sum; j++) {
            double f;
            if(j < t[i - 1])
                f = v[i] + t[i - 1] - j;
            else if(j <= t[i])
                f = v[i];
            else
                f = v[i] + j - t[i];
            train[j] = min(train[j], f);
        }
    }
    for(j = 0; j <= sum; j++) {
        train[j] = min(train[j], (double)j);
        train[j] = min(train[j], (double)sum - j);
    }

    double ret = 0;
    for(i = 1; i <= sum; i++) {
        ret += (train[i] + train[i - 1]) / 8;
    }
	printf("%.13f\n",ret);
    /*
	cout << ret << endl;
    
	for(i = 0; i <= sum; i++) {
        cout << train[i] << " ";
    }
    cout << endl;
	cout << sum << endl;
	*/
    return 0;
}