#include<bits/stdc++.h>
#define title "title"
#define ll long long
#define ull unsigned ll
#define fix(x) fixed<<setprecision(x)
#define pii pair<int,int>
#define vint vector<int>
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define red(i,a,b) for(int i=(a);i>=(b);i--)
#define db double
#define ld long db
using namespace std;
void Freopen(){
	freopen(title".in","r",stdin);
	freopen(title".out","w",stdout);
}
ll read(){
	ll g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
const int N=1e3+5;
int n,cnt;
ll x[N],y[N],len[N];
signed main(){
	//freopen("a","r",stdin);
	n=read();rep(i,1,n)x[i]=read(),y[i]=read();
	int re=abs(x[1]+y[1])&1;
	rep(i,2,n)if((abs(x[i]+y[i])&1)^re)return cout<<-1,signed();
	cout<<32-re<<'\n'<<1<<' ';len[++cnt]=1;
	if(re){rep(i,1,30)cout<<(len[++cnt]=(1<<i))<<' ';cout<<'\n';}
	else{rep(i,0,30)cout<<(len[++cnt]=(1<<i))<<' ';cout<<'\n';}
	rep(i,1,n){
		ll nx=0,ny=0;string s="";
		red(j,cnt,1){
			ll dx=x[i]-nx,dy=y[i]-ny;
			if(abs(dx)>abs(dy)){if(dx>0)nx+=len[j],s+='R';else nx-=len[j],s+='L';}
			else{if(dy>0)ny+=len[j],s+='U';else ny-=len[j],s+='D';}
		}reverse(s.begin(),s.end());cout<<s<<'\n';
	}return signed();
}