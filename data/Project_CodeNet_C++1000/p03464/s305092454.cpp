#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 0x3F3F3F3F;
const ll INFLL = 0x3F3F3F3F3F3F3F3FLL;

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<ll> v(n);
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i];
	
	if(v[n - 1] != 2LL){
		cout << "-1\n";
		return 0;
	}
	
	ll curr = 2LL;
	ll minAns = 2LL, maxAns = 3LL;
	
	for(int i = n - 2 ; i >= 0 ; i --){
		ll lowm = (minAns + (v[i] - 1))/v[i];
		lowm *= v[i];
		
		ll him = maxAns/v[i];
		him *= v[i];
		
		minAns = lowm;
		maxAns = him + (v[i] - 1LL);
	}
	
	if(minAns > maxAns){
		cout << "-1\n";
		return 0;
	}
	
	cout << minAns << " " << maxAns << "\n";
	
	return 0;
}