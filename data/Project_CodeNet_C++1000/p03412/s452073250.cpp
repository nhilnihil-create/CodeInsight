// 18:45 - 18:51
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define lch (o << 1)
#define rch (o << 1 | 1)

typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> pint;

const int N = 200000 + 5;
const int K = 28 + 2;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;

int a[N], b[N];

int main(){
	int n; scanf("%d", &n);

	for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(int i=1; i<=n; i++)
		scanf("%d", &b[i]);

	ll ans = 0;
	for(int j=0; j<K; j++){
		vector<int> s;
		ll d = 1LL << (j+1);
		for(int i=1; i<=n; i++){
			s.push_back(a[i] % d);
			s.push_back(a[i] % d + d);
		}
		sort(s.begin(), s.end());
		
		for(int i=1; i<=n; i++){
			auto r = lower_bound(s.begin(), s.end(), 2 * d - b[i] % d);
			auto l = lower_bound(s.begin(), s.end(), 3 * d / 2 - b[i] % d);
			if((r - l) & 1) ans ^= 1LL << j;
		}
	}
	
	printf("%lld\n", ans);

	return 0;
}