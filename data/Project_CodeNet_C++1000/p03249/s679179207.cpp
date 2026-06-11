#include <bits/stdc++.h>

typedef long long int int64;
struct vertex {
	int i;
	int64 val;
	int size;
	int parent;
	int next,child;
	int depth;
} v[100003];
void dfs(int i)
{
	for(int j = v[i].child;j != -1;j = v[j].next) {
		v[j].depth = v[i].depth + 1;
		dfs(j);
	}
}
int n;
bool cmp1(const vertex &a,const vertex &b) {
	return a.val < b.val;
}
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;++i) {
		scanf("%lld",&v[i].val);
		v[i].i = i + 1;
		v[i].size = 1;
	}
	std::sort(v,v+n,cmp1);
	std::map<int64,int> m;
	for(int i = 0;i < n;++i) {
		m[v[i].val] = i;
		v[i].next = v[i].child = -1;
	}
	for(int i = n - 1;i >= 1;--i) {
		int64 val2 = v[i].val - n + 2LL * v[i].size;
		std::map<int64,int>::iterator it = m.find(val2);
		if(it == m.end()) {
			printf("-1\n");
			return 0;
		}
		v[i].parent = it->second;
		v[v[i].parent].size += v[i].size;
		v[i].next = v[v[i].parent].child;
		v[v[i].parent].child = i;
	}
	int64 dsum = 0;
	dfs(0);
	for(int i = 0;i < n;++i) {
		dsum += v[i].depth;
	}
	if(v[0].size == n && v[0].val == dsum) {
		for(int i = 1;i < n;++i) {
			printf("%d %d\n", v[i].i, v[v[i].parent].i);
		}
	} else {
		printf("-1\n");
	}
}
