#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define lowbit(x) x&(-x)
#define PII  pair<int, int> 
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e5 + 5;
using namespace std;
 
int p[11], c[11];
 
int main()
{
	int D, G; scanf("%d %d", &D, &G);
	for(int i = 0; i < D; i++) scanf("%d %d", p + i, c + i);
	int ans = inf;
	for(int i = 0; i < (1 << D); i++){
		ll sum = 0;
		int cnt = 0;
		for(int j = 0; j < D; j++){
			if((i >> j) & 1){
				sum += p[j] * (j + 1) * 100 + c[j];
				cnt += p[j];
			}
		}
		for(int j = D - 1; j >= 0; j--){
			if((i >> j) & 1) continue;
			if(sum >= G) continue;
			int q = min((G - sum)/((j + 1) * 100), (ll)p[j]);
			cnt += q;
			sum += (j + 1) * 100 * q;
		}
		if(G <= sum) ans = min(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}