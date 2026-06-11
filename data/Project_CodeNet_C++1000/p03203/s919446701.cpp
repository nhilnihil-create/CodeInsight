#include <bits/stdc++.h>
using namespace std;
#define iinf 2000000000
#define linf 1000000000000000000LL
#define ulinf 10000000000000000000ull
#define MOD1 1000000007LL
#define mpr make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned long UL;
typedef unsigned short US;
typedef pair < int , int > pii;
clock_t __stt;
inline void TStart(){__stt=clock();}
inline void TReport(){printf("\nTaken Time : %.3lf sec\n",(double)(clock()-__stt)/CLOCKS_PER_SEC);}
template < typename T > T MIN(T a,T b){return a<b?a:b;}
template < typename T > T MAX(T a,T b){return a>b?a:b;}
template < typename T > T ABS(T a){return a>0?a:(-a);}
template < typename T > void UMIN(T &a,T b){if(b<a) a=b;}
template < typename T > void UMAX(T &a,T b){if(b>a) a=b;}
int n,h,w,x[200005],y[200005],p[200005];
bool cmp(int a,int b){
	return mpr(y[a],x[a])<mpr(y[b],x[b]);
}
int main(){
    // inputting start
    // 数据结构记得初始化！ n，m别写反！
    int i,j,k,res;
	scanf("%d%d%d",&h,&w,&n);
	for(i=0;i<n;++i){
		scanf("%d%d",x+i,y+i);
		--x[i];--y[i];
		x[i]-=y[i];
	}
    #ifdef LOCAL
        TStart();
    #endif
    // calculation start
    // 数据结构记得初始化！ n，m别写反！
    for(i=0;i<n;++i) p[i]=i;
	sort(p,p+n,cmp);
	int tp=0;
	res=h;
	for(i=0;i<n;++i){
		int X=x[p[i]],Y=y[p[i]];
		if(tp<X)
			UMIN(res,X+Y);
		else if(tp==X)
			++tp;
	}
	printf("%d\n",res);
    #ifdef LOCAL
        TReport();
    #endif
    return 0;
}