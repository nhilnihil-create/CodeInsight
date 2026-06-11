#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MIN(_A, _B) (((_A) < (_B)) ? (_A) : (_B))

int h, w, n;
std::map<int, bool> M[233333];
int p[233333][2];
int f[233333];
int ans;

int main(){
	scanf("%d %d %d", &h, &w, &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &p[i][0], &p[i][1]);
		M[p[i][0]][p[i][1]] = true;
	}
	ans = h;
	f[1] = 1;
	for(int i = 2; i <= h; i++){
		if(M[i][f[i - 1] + 1]) f[i] = f[i - 1];
		else f[i] = f[i - 1] + 1;
	}
	for(int i = 1; i <= n; i++){
		if(p[i][0] == 1) continue;
		if(p[i][1] <= f[p[i][0] - 1]) ans = MIN(ans, p[i][0] - 1);
	}
	printf("%d\n", ans);
	return 0;
}