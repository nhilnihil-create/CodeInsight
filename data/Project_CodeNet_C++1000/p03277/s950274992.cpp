#include <bits/stdc++.h>
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);
#define pb push_back
#define eb emplace_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define sorv(V) sort(allv(V))
#define revv(V) reverse(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define clv(V) (V).clear()
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100055;
const int MX = 500055;

struct BIT {
	int d[MX];
	void init() { fill(d, d+MX, 0); }
	void upd(int x, int r) {
		for(x += MAXN; x < MX; x += rb(x))
			d[x] += r;
	}
	int get(int x) {
		int r = 0; for(x += MAXN; x; x -= rb(x))
			r += d[x];
		return r;
	}
} bit;

vector<int> XV;
int A[MAXN], B[MAXN];

int N;

ll f(int X) {
	for(int i = 1; i <= N; i++)
		B[i] = (A[i] <= X ? 1 : 0);
	for(int i = 1; i <= N; i++) B[i] += B[i-1];

	ll ret = 0;
	bit.init(); bit.upd(0, 1);
	for(int i = 1; i <= N; i++) {
		ret += bit.get(B[i]*2 - i - 1);
		bit.upd(B[i]*2 - i, 1);
	}
	return ret;
}

int getAns() {
	int s = 0, e = sz(XV)-1; for(int m; s < e;) {
		m = (s+e) >> 1;
		if(f(XV[m]) <= ll(N) * (N+1) / 4) s = m+1;
		else e = m;
	}
	return XV[s];
}

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
		XV.eb(A[i]);
	}
	sorv(XV); univ(XV);

	cout << getAns() << endl;

	return 0;
}