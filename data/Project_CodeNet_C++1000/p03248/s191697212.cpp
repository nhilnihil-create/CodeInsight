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
int read(){
	int g=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){g=g*10+ch-'0';ch=getchar();}
	return g*f;
}
const int N=1e5+5;
char s[N];
int n,a[N];
signed main(){
	//freopen("a","r",stdin);
	scanf("%s",s+1);n=strlen(s+1);rep(i,1,n)a[i]=(s[i]=='1');
	rep(i,1,n)if(a[i]&&!a[n-i])return cout<<-1,signed();
	if(!a[1])return cout<<-1,signed();
	int now=1;
	rep(i,2,n/2)if(a[i]){rep(j,now,i-1)cout<<i<<' '<<j<<'\n';now=i;}
	rep(i,now,n-1)cout<<n<<' '<<i<<'\n';
	return signed();
}