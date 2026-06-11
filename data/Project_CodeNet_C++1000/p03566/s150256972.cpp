#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong N, T = 0;
	vector<llong> t,v;

	cin >> N;
	t.resize(N+1, 0), v.resize(N+1,0);
	for(int i = 1; i <= N; i++){
		cin >> t[i];
		t[i] += t[i-1];
	}
	for(int i = 1; i <= N; i++)
		cin >> v[i];

	map<double, long double> res;
	for(llong i = N; i >= 1; i--){
		for(double j = t[i]; j >= t[i-1]; j -= 0.5){
			if(res.find(j) == res.end())
				res[j] = inf;
			if(i == N)
				res[j] = min({(long double)res[j],(long double)t[i]-j, (long double)v[i]});
			else if(i == 1)
				res[j] = min({(long double)res[j], (long double)j, res[j+0.5]+0.5, (long double)v[i]});
			else{
				res[j] = min({(long double)res[j], res[j+0.5]+0.5, (long double)v[i]});
			}
		}
	}

	// for(double i = 0; i < t[N]; i += 0.5)
	// 	cerr << res[i] << endl;

	long double ans = 0.0;
	long double now = 0;
	for(double i = 0; i < t[N]; i += 0.5){
		if(now < res[i+0.5]){
			ans += (now+now+0.5)/4.0;
			now += 0.5;
		}else if(now > res[i+0.5]){
			ans += (now+now-0.5)/4.0;
			now -= 0.5;
		}else{
			ans += now/2.0;
		}
	}

	cout << fixed << setprecision(12) << ans << endl;

	return 0;
}
