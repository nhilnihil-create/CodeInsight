#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
//#define ivorysi
#define MAXN 100005
#define eps 1e-8
#define pb push_back
using namespace std;
typedef long long int64;
typedef double db;
int N,M;
int P[MAXN],fa[MAXN];
int getfa(int x) {
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    scanf("%d%d",&N,&M);
    for(int i = 1 ; i <= N ; ++i) scanf("%d",&P[i]);
    for(int i = 1 ; i <= N ; ++i) fa[i] = i;
    int x,y;
    for(int i = 1 ; i <= M ; ++i) {
    	scanf("%d%d",&x,&y);
    	fa[getfa(x)] = getfa(y);
    }
    int cnt = 0;
    for(int i = 1 ; i <= N ; ++i) {
    	if(getfa(P[i]) == getfa(i)) ++cnt;
    }
    printf("%d\n",cnt);
}