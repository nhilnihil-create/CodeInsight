#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	
	long N,M; cin >> N >> M;

	vector<pair<long,long>> drink(N,make_pair(0,0));
	for (int i = 0; i < N; i++) {
		long a,b; cin >> a >> b;
		drink[i] = make_pair(a,b);
	}
	sort(drink.begin(),drink.end());

	long ans = 0;	
	for (int i = 0; i < N; i++) {
		if (drink[i].second <= M) {
			ans += drink[i].first * drink[i].second;	
			M -= drink[i].second;
		}else {
			ans += drink[i].first * M;		
			M -= M;
		}
		if (M == 0) {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
