#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=2e5+5;

int h,c,n,x,y;
vector<int> p[N];
#define pb(a) push_back(a)

bitset<N> f;

int main() {
	scanf("%d%d",&h,&c);
	scanf("%d",&n);
	fo(i,1,n) {
		scanf("%d%d",&x,&y);
		if (x==2&&y==1) {puts("1");return 0;}
		p[x].pb(y);
	}
	f[1]=1;
	fo(i,2,h) {
		f|=f<<1;
		for(int j=0;j<p[i].size();j++) f[p[i][j]]=0;
		for(int j=0;j<p[i+1].size();j++) 
			if (f[p[i+1][j]]) {
				printf("%d\n",i);
				return 0;
			}
	}
	printf("%d\n",h);
	return 0;
}