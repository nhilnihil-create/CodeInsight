#include <bits/stdc++.h>

struct vertex {
	int estart;
	int parent;
	int max1,max2;
} v[200003];
struct edge {
	int enext;
	int to;
} e[400003];int en;
int n;
int rad;
void dfs(int i)
{
	int max1 = -1, max2 = -1;
	for(int j = v[i].estart;j != -1;j = e[j].enext) {
		int to = e[j].to;
		if(to == v[i].parent) continue;
		v[to].parent = i;
		dfs(to);
		if(v[to].max1 > max1) {
			max2 = max1;
			max1 = v[to].max1;
		} else if(v[to].max1 > max2) {
			max2 = v[to].max1;
		}
	}
	++max1, ++max2;
	if(max1 + max2 > rad)
		rad = max1 + max2;
	v[i].max1 = max1;
	v[i].max2 = max2;
}
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;++i) {
		v[i].estart = -1;
	}
	for(int i = 0;i < n - 1;++i) {
		int a,b;
		scanf("%d%d",&a,&b);--a,--b;
		e[en].enext = v[a].estart;e[en].to = b;v[a].estart = en++;
		e[en].enext = v[b].estart;e[en].to = a;v[b].estart = en++;
	}
	dfs(0);++rad;
	if(rad % 3 == 2) {
		printf("Second\n");
	} else {
		printf("First\n");
	}
}
