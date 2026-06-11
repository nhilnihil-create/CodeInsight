#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;

int n,m,Q;
int f[maxn][maxn];

int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for (int i = 1; i <= m; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		if (v < u) swap(u,v);
		for (int i = v; i <= n; i++) {
			f[u][i]++;
		}
	}
	//cout << "ah" << endl;
	int ret = 0;
	for (int j = 0; j < Q; j++){
		int p,q;
		scanf("%d%d",&p,&q);
		int ret = 0;
		for (int i = p; i <= q; i++) {
			ret += f[i][q];
		}
		printf("%d\n",ret);
	}
	return 0;
}