// Comment
//

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

const int MAX_N = 1e5 + 100;
const int CONST = MAX_N;

struct BIT {
	int P; vector<int> val;
	BIT(int n) {
		P = n + CONST + 100;
		val = vector<int>(P, 0);
	}
	void update(int v, int k) {
		for(v+=CONST; v<P; v+=v&-v) val[v] += k;
	}
	int getSum(int v) {
		int res = 0;
		for(v+=CONST; v>0; v-=v&-v) res += val[v];
		return res;
	}
	int getSum(int a, int b) {
		return getSum(b) - getSum(a);
	}
};

vector<int> Xs;
int N, Nr[MAX_N];

int main() {
	cin >> N;
	for(int i=0; i<N; i++) {
		scanf("%d", &Nr[i]);
		Xs.push_back(Nr[i]);
	}
	sort(ALL(Xs));
	Xs.erase(unique(ALL(Xs)), Xs.end());
	int ans = -1;
	ll all = 1ll * N * (N+1) / 2;
	for(int l=0, r=SZ(Xs)-1; l<=r; ) {
		int m = (l+r)>>1;
		int nr = Xs[m];

		int sum = 0;
		ll cnt = 0;
		BIT bit = BIT(MAX_N);
		bit.update(0, 1);

		for(int i=0; i<N; i++) {
			int v = (Nr[i] >= nr) * 2 - 1;
			sum += v;
			cnt += bit.getSum(sum);
			bit.update(sum, 1);
		}
		if (cnt >= all - (all/2+1) + 1) {
			ans = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	printf("%d\n", Xs[ans]);
	return 0;
}
