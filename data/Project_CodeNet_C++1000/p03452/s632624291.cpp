#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int p[N], rec[N];

int find(int x){
	if (p[x] == x) return x;
	int fa = find(p[x]);
	rec[x] += rec[p[x]];
	return p[x] = fa;
}

bool same(int x, int y){
	return find(x) == find(y);
}

void unite(int x, int y, int val){
	int fx = find(x), fy = find(y);
	p[fx] = fy;
	rec[fx] = rec[y] - rec[x] + val;
}

int main(){
	int n, m, x, y, d;
	scanf("%d %d",&n,&m);
	for (int i = 1; i <= n; i++){
		p[i] = i;
		rec[i] = 0;
	}
	for (int i = 1; i <= m; i++){
		scanf("%d %d %d",&x,&y,&d);
		if (same(x, y)){
			if (rec[x] - rec[y] != d){
				printf("No\n");
				return 0;
			}
		}
		else unite(x, y, d);
	}
	printf("Yes\n");
	return 0;
}