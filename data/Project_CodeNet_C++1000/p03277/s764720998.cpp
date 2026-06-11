#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair < ll, int > pli;

const int N = 2e5 + 500;
const int OFF = N / 2;

int A[N], P[N], loga[N], n;

inline int get(int l, int r){
	return P[r] - (l ? P[l - 1] : 0);
}

void add(int x, int y = 1){
	for(x += OFF; x < N; x += x & -x)
		loga[x] += y;
}

int query(int x){
	int ret = 0;
	for(x += OFF; x ; x -= x & -x)
		ret += loga[x];
	return ret;
}

bool check(int x){
	P[0] = (A[0] >= x ? 1 : -1);
	for(int i = 1;i < n;i++)
		P[i] = P[i - 1] + (A[i] >= x ? 1 : -1);
	memset(loga, 0, sizeof(loga));
	add(0);
	ll ret = 0;
	for(int i = 0;i < n;i++){
		ret += query(P[i]);
		add(P[i]);
	}
	return ret >= ((ll)n * (n + 1) / 2 + 1) / 2;
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
		scanf("%d", A + i);
	int ans = 0;
	for(int i = 30;i >= 0;i--)
		if(check(ans + (1 << i)))
			ans += (1 << i);
	printf("%d\n", ans);
}