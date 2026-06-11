#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(ll (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(ll (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
const ll MOD=1e9+7;
using namespace std;
const ll MAX = 100005;

signed main(){
	int N, C;
	cin >> N >> C;
	vector<vector<ll>> ch(C, vector<ll>(2*MAX, 0));
	vector<ll> chall(2*MAX, 0);
	for(int i=0;i<N;i++) {
		int s, t, c;
		cin >> s >> t >> c;
		c--;
		ch[c][2*s]++;
		ch[c][2*t]--;
	}

	for(int i=1;i<2*MAX;i++) {
		for(int j=0;j<C;j++) {
			ch[j][i] += ch[j][i-1];
		}
	}
	for(int i=2;i<2*MAX;i+=2) {
		for(int j=0;j<C;j++) {
			if(ch[j][i-1] < ch[j][i]) {
				ch[j][i-1]++;
			}
		}
	}
	for(int i=0;i<2*MAX;i++) {
		for(int j=0;j<C;j++) {
			chall[i] += ch[j][i];
		}
	}
	ll ans = 0;
	for(int i=0;i<2*MAX;i++)
		if(ans < chall[i])
			ans = chall[i];

	cout << ans << endl;
}