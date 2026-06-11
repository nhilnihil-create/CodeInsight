/*
发现有解的充要条件是有一个形为AABBAABBAABB的环
此时每一个点至少与两个不同颜色的点相连
对于初始不合法的点直接删掉，判断删掉后与其相连的点是否变为不合法
类似拓扑排序 
*/
#include<bits/stdc++.h> 
#define gc getchar()
#define pc putchar 
inline int read() { 
	int x = 0,f = 1; 
	char c = gc; 
	while(c < '0' || c > '9') {if(c == '-')f = -1; c = gc;} 
	while(c <= '9' && c >= '0') x = x * 10 + c - '0',c = gc; 
	return x * f; 
} 
void print(long long  x) { 
	if(x < 0) { 
		pc('-'); 
		x = -x; 
	} 
	if(x >= 10) print(x / 10); 
	pc(x % 10 + '0'); 
} 
const int maxn = 1000007; 
int val[maxn]; 
int n,m; 
struct node {	
	int v,next; 
} edge[maxn]; 
int head[maxn],num = 0; 
inline void add_edge(int u,int v) { 
	edge[++ num].v = v; edge[num].next = head[u];head[u] = num; 
} 
int d[maxn][2]; 
std::queue<int>q; 
char s[maxn]; 
bool vis[maxn];  
int main() { 
	n = read(),m = read();
	scanf("%s",s + 1); 
	for(int i = 1;i <= n;++ i) {
		char c = s[i]; 
		if(c == 'A') val[i] = 0; 
		else val[i] = 1; 
	} 
	for(int u,v,i = 1;i <= m;++ i) { 
		u = read(),v = read(); 
		add_edge(u,v); add_edge(v,u); 
		d[u][val[v]] ++,d[v][val[u]]++;  
	} 
	int count = 0; 
	for(int i = 1;i <= n;++ i)  
		if(!d[i][1] || !d[i][0]) 
			q.push(i),count ++ ,vis[i] = 1;   
	while(!q.empty()) { 
		int u = q.front(); q.pop(); 
		for(int i = head[u];i;i = edge[i].next) { 
			int v = edge[i].v; 
			d[v][val[u]] --; 
		 	if((!d[v][1] || !d[v][0] )&& !vis[v]) {
		 		q.push(v); count++; vis[v] = 1; 
			 } 
		} 
	} 
	puts(count == n ? "No" : "Yes"); 
	return 0; 
} 