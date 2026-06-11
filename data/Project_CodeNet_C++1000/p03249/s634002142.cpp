#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
int n, C[N_];
vector<int>E[N_];
struct point {
	long long x;
	int num;
	bool operator<(const point &p)const {
		return x != p.x ? x < p.x : num < p.num;
	}
}w[N_];
long long sum;
void DFS(int a, int d) {
	sum += d;
	for (auto &x : E[a])DFS(x, d + 1);
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i].x);
		w[i].num = i, C[i] = 1;
	}
	sort(w + 1, w + n + 1);
	for (i = n; i > 1; i--) {
		int t = w[i].num;
		long long nx = w[i].x - n + C[t] * 2;
		point tp = { nx,-1 };
		int j =  lower_bound(w + 1, w + n + 1, tp) - w; 
		if (nx >= w[i].x || j<1 || j>n || w[j].x != nx) {
			puts("-1");
			return 0;
		}
		C[w[j].num] += C[t];
		E[w[j].num].push_back(t);
	}
	DFS(w[1].num, 0);
	if (sum != w[1].x)puts("-1");
	else {
		for (i = 1; i <= n; i++)for (auto &x : E[i])printf("%d %d\n", i, x);
	}
}