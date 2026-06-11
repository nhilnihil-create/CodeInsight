#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define qwq(x) cerr<<"# "<<#x<<" = "<<x<<endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=5005;
const ll inf=1e18;
int s[N][N],a[N],n,m,A,B;
ll f[N][N],ans;

int S(int l,int r,int d,int u){
	return l>r?0:s[r][u]-s[l-1][u]-s[r][d-1]+s[l-1][d-1];
}

int main(){
	read(n),read(A),read(B);
	rep(i,1,n)read(a[i]),s[i][a[i]]=1;
	rep(i,1,n)rep(j,1,n)
		s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	ans=(ll)min(A,B)*(n-1);
	memset(f,0x3f,sizeof f);
	a[0]=1,f[0][0]=0;
	rep(i,1,n){
		rep(j,0,i-1)
			if(f[i-1][j]<inf){
				f[i][j]=f[i-1][j];
				if(a[j]<=a[i]){
					f[i][i]=min(f[i][i],f[i-1][j]
							+(ll)A*S(j+1,i-1,a[j],n)
							+(ll)B*S(j+1,i-1,1,a[i]));
				}
			}
		ans=min(ans,f[i][i]	+(ll)A*S(i+1,n,a[i],n)
							+(ll)B*S(i+1,n,1,a[i]));
	}
	cout<<ans<<endl;
	return 0;
}