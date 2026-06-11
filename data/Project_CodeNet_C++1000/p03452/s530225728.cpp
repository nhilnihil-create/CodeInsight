#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
inline int read(){int now=0;register char c=getchar();for(;!isdigit(c);c=getchar());
for(;isdigit(c);now=now*10+c-'0',c=getchar());return now;}
#define For(i, x, y) for(int i=x;i<=y;i++)  
#define _For(i, x, y) for(int i=x;i>=y;i--)
#define Mem(f, x) memset(f,x,sizeof(f))  
#define Sca(x) scanf("%d", &x)
#define Sca2(x,y) scanf("%d%d",&x,&y)
#define Sca3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define Scl(x) scanf("%lld",&x);  
#define Pri(x) printf("%d\n", x)
#define Prl(x) printf("%lld\n",x);  
#define CLR(u) for(int i=0;i<=N;i++)u[i].clear();
#define LL long long
#define ULL unsigned long long  
#define mp make_pair
#define PII pair<int,int>
#define PIL pair<int,long long>
#define PLL pair<long long,long long>
#define pb push_back
#define fi first
#define se second 
typedef vector<int> VI;
const double eps = 1e-9;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; 
int N,M,K;
int tree[maxn];
int group[maxn];
void init(){
	for(int i = 1; i <= N; i ++){
		tree[i] = i;
		group[i] = 0;
	} 
}
int find(int x){
	if(x == tree[x]) return x;
	int fx = find(tree[x]);
	group[x] = group[tree[x]] + group[x];
	tree[x] = fx;
	return fx;
}
bool Union(int l,int r,int d){
	int fa = find(l),fb = find(r);
	if(fa == fb) return group[l] - group[r] == d;
	if(l + group[l] <= l + d + group[r]){
		tree[fa] = fb;
		group[fa] = -group[l] + d + group[r];
	}else{
		tree[fb] = fa;
		group[fb] = -group[r] - d + group[l];
	}
	return true;
}
int main(){
	Sca2(N,M); init();
	for(int i = 1; i <= M ; i ++){
		int l,r,d;
		scanf("%d%d%d",&l,&r,&d);
		if(!Union(l,r,d)){
			puts("No");
			exit(0);
		}
	}
	for(int i = 1; i <= N ; i ++){
		find(i);
		if(group[i] > 1e9){
			puts("No");
			exit(0);
		}
	}
	puts("Yes");
	return 0;
}