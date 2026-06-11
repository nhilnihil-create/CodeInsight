//Night's template
//orzakyrt
#include <bits/stdc++.h>
#define R register
#define LL long long
#ifdef __DEBUG__
	#define Debug (fprintf(stderr,"orzyrt\n"),fflush(stderr))
	#define debug(__a...) (fprintf(stderr,__a),fflush(stderr))
#else
	#define Debug ('orzyrt')
	#define debug(__a...) ('orzyrt')
#endif
inline void Compile(R char *s){
	char com[111];
	sprintf(com,"g++ %s.cpp -lm -o %s",s,s);
	system(com);
}
inline void setfile(R char *s){
	char inname[111],outname[111];
	sprintf(inname,"%s.in",s);
	sprintf(outname,"%s.out",s);
	freopen(inname,"r",stdin);
	freopen(outname,"w",stdout);
}
#ifdef __DEBUG__
	#define setfile(__a) (1)
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
	int n;
	int x[1111],y[1111];
	vector<int>ans;
	int main(){
		read(n);
		for(R int i=1;i<=n;++i){
			read(x[i]);read(y[i]);
			if(abs(x[i])+abs(y[i])&1^abs(x[1])+abs(y[1])&1){
				cout<<-1;
				return 0;
			}
		}
		for(R int i=0;i<31;++i)ans.push_back(1<<i);
		if(abs(x[1])+abs(y[1]) &1 ^1)ans.push_back(1);
		sort(ans.begin(),ans.end(),greater<int>());
		printf("%ld ",ans.size());
		for(R auto i:ans)printf("%d ",i);
		puts("");
		for(R int i=1;i<=n;++i){
			for(R auto j:ans){
				if(Abs(x[i])>Abs(y[i])){
					if(x[i]>0){
						x[i]-=j;
						putchar('R');
					}else{
						x[i]+=j;
						putchar('L');
					}
				}else{
					if(y[i]>0){
						y[i]-=j;
						putchar('U');
					}else{
						y[i]+=j;
						putchar('D');
					}
				}
			}
			puts("");
		}
		return 0;
	}
}
int main(){
	return Night::main();
}