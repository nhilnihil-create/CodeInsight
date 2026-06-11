#include<cstdio>
#include<cctype>
#include<algorithm>

using namespace std;

inline char nc(){ return getchar();static char buf[100000] , *p1,*p2; return p1 == p2 && (p1 = (p2 = buf) + fread(buf,1,100000,stdin),p1 == p2) ? EOF : *p1++;}
template<class T>inline void rd(T & x){ x = 0;int f = 1;char ch = nc(); for(;!isdigit(ch);ch = nc()) if(ch == '-') f = -1; for(;isdigit(ch);ch = nc()) x = x * 10 - 48 + ch; x *= f;}

typedef long long ll;

const int maxn = 1e5 + 10;
ll L[maxn] , R[maxn] , ans,n;

bool cmp(ll a,ll b) { return a > b;}
void calc(ll L[],ll R[]){
	ll tmp = 0;
	for(int i = 1;i <= n * 2;i++) {
		if(i % 2 == 1) tmp += L[i / 2] ; 
		else tmp += R[i / 2] ;
		ans = max(ans,tmp);
	}
}
int main(){
	rd(n);
	for(int i = 1;i <= n;i++){
		rd(L[i]); rd(R[i]); R[i] = -R[i];
	}
	sort(L + 1,L + n + 1,cmp); sort(R + 1,R + n + 1,cmp);
	calc(L,R) ; calc(R,L);
	printf("%lld",ans * 2);
	return 0;
}