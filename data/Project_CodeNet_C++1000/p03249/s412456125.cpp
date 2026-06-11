#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<pli> vpli;

inline ll read(){
    ll Hashimoto=0;
	bool Kanna=1;
    char I_Love=getchar();
    while(I_Love<'0'||I_Love>'9'){
        if(I_Love=='-')Kanna=0;
        I_Love=getchar();
    }
    while(I_Love>='0'&&I_Love<='9'){
        Hashimoto=Hashimoto*10+I_Love-'0';
        I_Love=getchar();
    }
    return (Kanna?Hashimoto:-Hashimoto);
}
template<typename T1,typename T2> inline void Umax(T1 &a,T2 b){
	if(a<b)a=b;
}
template<typename T1,typename T2> inline void Umin(T1 &a,T2 b){
	if(a>b)a=b;
}

#define I_Love_Hashimoto_Kanna main
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define filein(s) freopen(s,"r",stdin);
#define fileout(s) freopen(s,"w",stdout);
#define file freopen("I_Love_Hashimoto_Kanna.out","w",stdout);
#define RE cout<<"I_Love_Hashimoto_Kanna"<<endl;
#define Tone(Kanna) cout<<Kanna<<endl;
#define Tall(Hashimoto,Kanna) for(int I_Love=0;I_Love<(Kanna);++I_Love)cout<<Hashimoto[I_Love]<<(I_Love==(Kanna)-1?"\n":" ");
#define FOR(I_Love,Hashimoto,Kanna) for(int I_Love=Hashimoto;I_Love<(Kanna);++I_Love)
#define MP(Hashimoto,Kanna) make_pair(Hashimoto,Kanna)
#define REV(Kanna) reverse(Kanna.begin(),Kanna.end());
#define SORT(Kanna) sort(Kanna.begin(),Kanna.end());
#define UNIQUE(Kanna) Kanna.erase(unique(Kanna.begin(),Kanna.end()),Kanna.end());
#define inf (int)1e9
#define linf (ll)1e18
#define mod (inf+7)

int n;
pli a[111111];
int s[111111];
int f[111111];

int I_Love_Hashimoto_Kanna() {
	//完全想清楚了再开始写。
	//写不顺、不知道怎么写、很乱的时候，停下来好好想想。
	//做得慢总比做不出好。
	fastio;
	n=read();
	FOR(i,0,n){
		a[i]={read(),i};
		s[i]=1;
	}
	sort(a,a+n);
	ll sum=0;
	for(int i=n-1;i>0;--i){
		int j=lower_bound(a,a+n,MP(a[i].first-(n-s[i]-s[i]),-1))-a;
		if(i==j||a[j].first!=a[i].first-(n-s[i]-s[i])){
			Tone(-1);
			return 0;
		}
		f[i]=j;
		s[j]+=s[i];
		sum+=s[i];
	}
	if(sum!=a[0].first){
		Tone(-1);
		return 0;
	}
	FOR(i,1,n){
		printf("%d %d\n",a[i].second+1,a[f[i]].second+1);
	}
	return 0;
}
