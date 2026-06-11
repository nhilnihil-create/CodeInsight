#include <iostream>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[1<<18];
P p[1<<18];
llint dp[1<<18];

P maxp(P x, P y)
{
	if(x.first == y.first) return make_pair(x.first, y.first);
	if(y > x) swap(x, y);
	if(x.second > y.first) return x;
	else return make_pair(x.first, y.first);
}

int main(void)
{
	cin >> n;
	llint S = 1<<n;
	
	for(int i = 0; i < S; i++) cin >> a[i];
	for(int i = 0; i < S; i++) p[i] = make_pair(a[i], 0);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < S; j++){
			if(j&(1<<i)) p[j] = maxp(p[j], p[j^(1<<i)]);
		}
	}
	
	dp[0] = 0;
	for(int i = 1; i < S; i++){
		dp[i] = max(dp[i-1], p[i].first + p[i].second);
	}
	
	for(int i = 1; i < S; i++) cout << dp[i] << endl;
	return 0;
}