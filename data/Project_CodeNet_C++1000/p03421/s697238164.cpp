#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 3e5 + 10;

int N, A, B, Nr[MAX_N];
int main() {
	cin >> N >> A >> B;
	if(N > 1ll * A * B || N < A + B - 1) return puts("-1") < 0;
	int rest = N;
	Nr[0] = A, rest -= A;
	for(int i=1; i<B; i++) Nr[i] = 1, rest -= 1;
	for(int i=1; i<B; i++) {
		int v = min(rest, A-1);
		Nr[i] += v, rest -= v;
	}
	rest = N;
	for(int i=0; i<B; i++) {
		for(int ix=rest-Nr[i]; ix<rest; ix++) printf("%d ", ix+1);
		rest -= Nr[i];
	}
	puts("");
	return 0;
}
