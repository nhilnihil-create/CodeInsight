#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, k = -1, m;
vector < int > g[N];

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d",&n);
	n += n;
	for(int i = 1; i <= n; i++)
		if(1ll*i*(i + 1) == n){
			k = i + 1;
			break;
		}
	if(k == -1){
		puts("No");
		return 0;
	}
	puts("Yes");
	m = 1;
	for(int i = 1; i <= k; i++)
		for(int j = i + 1; j <= k; j++){
			g[i].pb(m);
			g[j].pb(m);
			m++;
		}
	printf("%d\n", k);
	for(int i = 1; i <= k; i++,puts("")){
		printf("%d ", k - 1);
		for(int j = 0; j < g[i].size(); j++)
			printf("%d ", g[i][j]);
	}
	return 0;
}