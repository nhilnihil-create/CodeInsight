#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
bool u[500010];
LL ans,t;
int l[500010],now,n,rp,r[500010],p[500010],q[500010],P,Q;
bool cmp(int A,int B){
	return (l[A]>l[B]);
}
bool cmp1(int A,int B){
	return (r[A]<r[B]);
}
void RF(){
	FOR(i,1,n) p[i]=i;
	sort(p+1,p+n+1,cmp);
	FOR(i,1,n) q[i]=i;
	sort(q+1,q+n+1,cmp1);
	//right first
	P=Q=1;
	now=0;
	t=0;
	memset(u,0,sizeof(u));
	for (rp=1;;++rp){
		while (P<=n && u[p[P]]) ++P;
		while (Q<=n && u[q[Q]]) ++Q;
		if (rp&1){
			if (P>n || l[p[P]]<=now){
				t+=abs(now);
				break;
			}
			u[p[P]]=1;
			t+=l[p[P]]-now;
			now=l[p[P]];
		}
		else{
			if (Q>n || r[q[Q]]>=now){
				t+=abs(now);
				break;
			}
			u[q[Q]]=1;
			t+=now-r[q[Q]];
			now=r[q[Q]];
		}
	}
	ans=max(ans,t);
}
int main(){
	cin>>n;
	FOR(i,1,n) getint(l[i]),getint(r[i]);
	ans=0;
	RF();
	FOR(i,1,n) swap(l[i],r[i]),l[i]=-l[i],r[i]=-r[i];
	RF();
	cout<<ans<<endl;
	return 0;
}