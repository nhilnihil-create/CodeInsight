#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define RI(a) scanf("%d",&a)
#define RII(a,b) scanf("%d%d",&a,&b)
#define RIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#ifdef leowang
#define debug(...) do{\
	fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
	_DO(__VA_ARGS__);\
}while(0)
template<typename I> void _DO(I&&x){cerr<<x<<endl;}
template<typename I,typename...T> void _DO(I&&x,T&&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif
//}}}
const ll maxn=80005;
const ll maxlg=__lg(maxn)+2;
const ll INF64=8000000000000000000LL;
const int INF=2000000000;

int t[maxn];
int v[maxn];

int T=0;

int s[maxn];
int main()
{
	REP(i,maxn) s[i]=INF;
	
	
	int n;
	cin>>n;
	REP(i,n) cin>>t[i+1];
	REP(i,n) cin>>v[i+1];
	v[n+1]=0,t[n+1]=0;
	v[0]=0,t[0]=0;
	int cur=0;
	
	
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<maxn;j++){
			if(j<=cur*2){
				s[j]=min(s[j],2*v[i]+(2*cur-j));
			}
			else if(j>=2*(cur+t[i])){
				s[j]=min(s[j],2*v[i]+(j-2*cur-2*t[i]));
			}
			else s[j]=min(s[j],2*v[i]);
		}
		cur+=t[i];
	}
	
	REP(i,n) T+=t[i+1];
	//cout<<T<<'\n';
	int ans=0;
	for(int i=0;i<2*T;i++){
		//cout<<s[i]<<' ';
		ans+=s[i]+s[i+1];
	}
	cout<<fixed<<setprecision(6)<<0.125*ans;
	return 0;
}










