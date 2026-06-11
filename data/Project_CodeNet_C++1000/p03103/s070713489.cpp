#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())
#define all(a) (a).begin(), (a).end()

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//print
#define pv(val) cerr << #val << '=' << (val) << endl

const int INF = 1e9;

int main(void){

	ll N, M; cin >> N >> M;

	vector<pair<ll, ll>> AB(N);
	REP(i,N){
		ll A, B; cin >> A >> B;
		AB[i] = make_pair(A, B);
	}

	SORT(AB);

	ll cnt = 0;
	ll ans = 0;
	int idx = 0;
	while(cnt != M){
		ll num = min((ll)AB[idx].second, M-cnt);
		ans += AB[idx].first * num;
		cnt += num;
		idx++;

	}

	cout << ans << endl;




	return 0;

}
