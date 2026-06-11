// Comment 
// easy, boring implement

#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
using ll = long long;
using pi = pair<int, int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 2e5 + 100;

int N;
ll Nr[MAX_N], Sum[MAX_N];
int Ix[2][MAX_N];

void fillIx(int ix[MAX_N]) {
	vector<ll> sum(MAX_N+1);
	for(int i=1; i<=N; i++) sum[i] = sum[i-1] + Nr[i];

	int j = 0;
	for(int i=1; i<=N; i++) {
		while(sum[j+1] <= sum[i] - sum[j+1]) j++;
		ix[i] = j;
	}
}

int main() {
	cin >> N;
	for(int i=1; i<=N; i++) {
		scanf("%lld", &Nr[i]);
		Sum[i] = Sum[i-1] + Nr[i];
	}
	for(int k=0; k<2; k++) {
		fillIx(Ix[k]);
		reverse(Nr+1, Nr+N+1);
	}
	reverse(Ix[1]+1, Ix[1]+N+1);
	for(int i=1; i<=N; i++) Ix[1][i] = N+1 - Ix[1][i];

	ll ans = LINF;
	for(int i=2; i<=N-2; i++) {
		vector<int> ls, rs;
		ls.push_back(Ix[0][i]);
		ls.push_back(Ix[0][i]+1);
		rs.push_back(Ix[1][i+1]-1);
		rs.push_back(Ix[1][i+1]-2);
		for(int l: ls) for(int r: rs) {
			if(!(0 < l && l < i && i < r && r < N)) continue;
			ll pp = Sum[l], qq = Sum[i] - Sum[l];
			ll rr = Sum[r] - Sum[i], ss = Sum[N] - Sum[r];
			ll now = max(max(pp, qq), max(rr, ss)) - min(min(pp, qq), min(rr, ss));
			ans = min(ans, now);
		}
	}
	cout << ans << endl;
	return 0;
}
