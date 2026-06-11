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
multiset < pii > all[2],cur[2];
int n,dir,pos;
LL res=-linf;
void solve(){
	LL ret=0LL;
	int i,j,k;
	for(i=0;i<n;++i){
		pii crv;
		if(dir&1){
			crv=*cur[1].begin();
			swap(crv.first,crv.second);
		}
		else crv=*cur[0].rbegin();
		cur[0].erase(cur[0].lower_bound(crv));
		cur[1].erase(cur[1].lower_bound(mpr(crv.second,crv.first)));
		dir^=1;
		if(pos>=crv.first && pos<=crv.second) continue;
		if(ABS(pos-crv.first)<ABS(pos-crv.second)){
			ret+=(LL)ABS(pos-crv.first);
			pos=crv.first;
		}
		else{
			ret+=(LL)ABS(pos-crv.second);
			pos=crv.second;
		}
	}
	UMAX(res,ret+(LL)ABS(pos));
}
int main(){
    // inputting start
    // 数据结构记得初始化！ n，m别写反！
    int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d",&j,&k);
		all[0].insert(mpr(j,k));
		all[1].insert(mpr(k,j));
	}
    #ifdef LOCAL
        TStart();
    #endif
    // calculation start
    // 数据结构记得初始化！ n，m别写反！
    cur[0]=all[0];cur[1]=all[1];
	pos=0;
	dir=0;
	solve();
	cur[0]=all[0];cur[1]=all[1];
	pos=0;
	dir=1;
	solve();
	printf("%lld\n",res);
    #ifdef LOCAL
        TReport();
    #endif
    return 0;
}