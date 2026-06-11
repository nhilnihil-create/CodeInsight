
// Problem : F - Distance Sums
// Contest : AtCoder - AtCoder Regular Contest 103
// URL : https://atcoder.jp/contests/arc103/tasks/arc103_d
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll > pil;
typedef pair<ll ,int> pli;
typedef pair<ll ,ll > pll;
#define rep(i,l,r) for(i=(l);i<=(r);++i)
#define per(i,l,r) for(i=(l);i>=(r);--i)
#define REP(i,l,r) for(i=(l);i< (r);++i)
#define PER(i,l,r) for(i=(l);i> (r);--i)
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define fi first
#define se second
#define it iterator
template<class IT>inline void cmx(IT &a,IT b){if(a<b)a=b;}
template<class IT>inline void cmn(IT &a,IT b){if(b<a)a=b;}
template<class IT>inline bool bmx(IT &a,IT b){if(a<b){a=b;return true;}else return false;}
template<class IT>inline bool bmn(IT &a,IT b){if(b<a){a=b;return true;}else return false;}
const int N=100005;
map<ll,int>M;
pli D[N];
int S[N],F[N];
inline void ac(){
	int n,i,a,s;ll w,d;
	scanf("%d",&n);
	rep(i,1,n){scanf("%lld",&D[i].fi);M[D[i].fi]=D[i].se=i;}
	sort(D+1,D+n+1);
	per(i,n,2){
		w=D[i].fi;
		a=D[i].se;
		//printf("w=%lld a=%d\n",w,a);
		s=++S[a];
		if((s<<1)>=n){printf("-1");return;}
		d=w+(s<<1)-n;
		if(!M[d]){printf("-1");return;}
		S[F[a]=M[d]]+=s;
		//printf("f=%d\n",F[a]);
	}
	w=-S[D[1].se];
	rep(i,1,n)w+=S[i];
	if(w==D[1].fi){rep(i,1,n)if(a=F[i])printf("%d %d\n",i,a);}
	else printf("-1");
}
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	
	ac();
	return 0;
}
#undef rep
#undef per
#undef REP
#undef PER
#undef mp
#undef pb
#undef pf
#undef pob
#undef pof
#undef fi
#undef se
#undef it