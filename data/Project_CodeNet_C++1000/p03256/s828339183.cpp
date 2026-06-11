#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int N=200005;
int n,m,h,t;
vector<int> e[N];
int cnt[N][2],q[N];
bool ok[N];
char s[N];
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	For(i,1,n) s[i]-='A',ok[i]=1;
	For(i,1,m){
		int x,y; scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
		cnt[x][s[y]]++; cnt[y][s[x]]++;
	}
	For(i,1,n)
		if (!cnt[i][0]||!cnt[i][1])
			q[++t]=i,ok[i]=0;
	while (h!=t){
		int x=q[++h]; ok[x]=0;
		for (int i=0;i<e[x].size();i++)
			if (ok[e[x][i]])
				if (!--cnt[e[x][i]][s[x]])
					q[++t]=e[x][i],ok[e[x][i]]=0;
	}
	puts(t==n?"No":"Yes");
}