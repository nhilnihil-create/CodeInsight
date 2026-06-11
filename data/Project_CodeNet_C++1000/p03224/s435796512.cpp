//Night's template
//orzakyrt
#include <bits/stdc++.h>
#define R register
#define LL long long
#ifdef __DEBUG__
	#define Debug (fprintf(stderr,"orzyrt\n"),fflush(stderr))
	#define debug(__a...) (fprintf(stderr,__a),fflush(stderr))
	#define setfile(__a) ('orzyrt')
	#define Compile(__a) system("g++ "__a".cpp -lm -o "__a)
#else
	#define Debug ('orzyrt')
	#define debug(__a...) ('orzyrt')
	#define setfile(__a) freopen(__a".in","r",stdin);freopen(__a".out","w",stdout)
	#define Compile(__a) ('orzyrt')
#endif
template<class TT>inline TT Max(R TT a,R TT b){return a<b?b:a;}
template<class TT>inline TT Min(R TT a,R TT b){return a<b?a:b;}
template<class TT>inline TT Abs(R TT a){return a<0?-a:a;}
template<class TT>inline TT cmin(R TT &a,R TT b){(b<a)&&(a=b);}
template<class TT>inline TT cmax(R TT &a,R TT b){(a<b)&&(a=b);}
using namespace std;
template<class TT>inline void read(R TT &x){
	x=0;R bool f=false;R char c=getchar();
	for(;c<48||c>57;c=getchar())f|=(c=='-');
	for(;c>47&&c<58;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	(f)&&(x=-x);
}
//end template

namespace Night{
	const int maxn = 2e5+10;
	int n,m,lim;
	int mp[555][555];
	int vis[maxn];
	int main(){
		read(n);
		for(R int i=2;i<=448;++i){
			vis[i*(i-1)/2]=i;
			if((i*(i-1))/2==n)lim=i;
		}
		if(!lim){
			puts("No");return 0;
		}
		R int x1=1,x2=2,y1=1,y2=1;
		for(R int i=1;i<=n;++i){
			mp[x1][y1]=mp[x2][y2]=i;
			if(y1==y2 && x2==x1+1){
				x2++;y2=1;
				y1++;x1=1;
			}else{
				y2++;x1++;
			}
		}
		printf("Yes\n");
		printf("%d\n",lim);
		for(R int i=1;i<=lim;++i){
			printf("%d ",lim-1);
			for(R int j=1;j<lim;++j){
				printf("%d ",mp[i][j]);
			}
			puts("");
		}
		return 0;
	}
}
int main(){
	return Night::main();
}