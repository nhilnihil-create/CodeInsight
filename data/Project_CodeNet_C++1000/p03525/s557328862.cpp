#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> D(N-1+1);
	map<ll, ll> m;
	m[0]++;
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&D[i]);
		m[D[i]]++;
	}
	queue<ll> que1, que2;
	que1.push(0);
	
	rep(i, 13) {
		if (m[i] > 2) {
			cout << "0" << endl;
			return 0;
		}
		if (m[i] > 1 && (i == 0 || i == 12)) {
			cout << "0" << endl;
			return 0;
		}
		while(!que1.empty()) {
			if (m[i] == 0) que2.push(que1.front());
			if (m[i] == 1) {
				que2.push(que1.front()+(1<<i));
				que2.push(que1.front()+(1<<((24-i)%24)));
			}
			if (m[i] == 2) que2.push(que1.front()+(1<<i)+(1<<((24-i)%24)));
			que1.pop();
		}
		while(!que2.empty()) {
			que1.push(que2.front());
			que2.pop();
		}
	}
	ll res = 0;
	while(!que1.empty()) {
		ll cnt = 100, start = -1;
		rep(i, 48) {
			// cout << (que1.front()&(1<<(i%24)));
			if ((que1.front()&(1<<(i%24)))) {
				if (start == -1) {
					start = i; 
				} else {
					cnt = min(cnt, (i-start)%24);
					start = i;
				}
			}
		}
		// cout << static_cast<bitset<24> >(que1.front()) << " " << cnt << endl;
		res = max(res, cnt);
		que1.pop();
	}
	cout << res << endl;
	return 0;
}

