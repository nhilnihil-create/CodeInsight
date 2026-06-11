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

const int MAX_N = 2e5 + 100;

int N;
int main() {
	cin >> N; 
	ll sum = 0;
	int minV = INF;
	for(int i=0; i<N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		sum += x;
		if(x > y && minV > y) minV = y;
	}
	if(minV == INF) puts("0");
	else printf("%lld\n", sum-minV);
	return 0;
}
