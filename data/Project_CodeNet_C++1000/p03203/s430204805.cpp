/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int maxn=200005;
int n,h,w;
set<int>s[maxn];

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	scanf("%d%d%d",&h,&w,&n);
	REP(i,w)s[h+1].insert(i);
	REP(i,n){
		int x,y;
		scanf("%d%d",&x,&y);
		s[x].insert(y);
	}
	int mx=1;
	REP(i,h){
		if(!s[i+1].empty()&&(*s[i+1].begin()<=mx)){
			printf("%d\n",i);
			return 0;
		}
		if(mx+1<=w&&!s[i+1].count(mx+1))mx++;
	}
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/
