#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
/*
const int SIZE = 1E5 + 9;
struct EDGES {
	int next, to, w;
} edge[SIZE << 1]; int cnt, head[SIZE];
int dep[SIZE], son[SIZE], top[SIZE], fa[SIZE], sze[SIZE];
int N, Tpos[SIZE], Ipos[SIZE], w[SIZE], Ind;
struct Node {
	int L, R, F; LL w, Lazy;
	Node() : F(Inf) {};
} Node[SIZE << 2];

void Add(int from, int to, int w) {
	edge[cnt].to = to; edge[cnt].w = w; edge[cnt].next = head[from]; head[from] = cnt++;
}

void FDFS(int now, int fat, int deep) {
	dep[now] = deep; fa[now] = fat; sze[now] = 1;
	for (int pos = head[now]; ~pos; pos = edge[pos].next)
		if (edge[pos].to != fat) {
			FDFS(edge[pos].to, now, deep + 1);
			w[edge[pos].to] = edge[pos].w;
			sze[now] += sze[edge[pos].to];
			if (sze[edge[pos].to] > sze[son[now]])
				son[now] = edge[pos].to;
		}
}

void SDFS(int now, int tops) {
	top[now] = tops; Tpos[now] = ++Ind; Ipos[Tpos[now]] = now;
	if (!son[now]) return;
	SDFS(son[now], tops);
	for (int pos = head[pos]; ~pos; pos = edge[pos].to)
		if (edge[pos].to != fa[now] && edge[pos].to != son[now])
			SDFS(edge[pos].to, edge[pos].to);
}

void BUILD(int now, int L, int R) {
	Node[now].L = L; Node[now].R = R;
	if (L == R) {
		Node[now].w = w[Ipos[L]]; return;
	}
	int Mid = (L + R) >> 1;
	BUILD(now << 1, L, Mid); BUILD(now << 1 | 1, Mid + 1, R);
	Node[now].w = max(Node[now << 1].w, Node[now << 1 | 1].w);
}

void Covpush(int now) {
	
}

void CovUpd(int now, int L, int R, LL w) {
	
}

int main() {
	scanf("%d", &N); memset(head, -1, sizeof head);
	for (int pos = 1, from, to, w; pos < N; pos++) {
		scanf("%d%d%d", &from, &to, &w); Add(from, to, w); Add(to, from, w);
	}
	FDFS(1, 0, 1); SDFS(1, 1);
}
*/

int main() {
	string str; cin >> str;
	str.erase(str.begin() + str.size() - 8, str.end());
	cout << str << endl;
}
