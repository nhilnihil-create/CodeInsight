#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef __int128 lll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005;
ll s[N],a[N],ans,n,x;

int main(){
	read(n),read(x);
	rep(i,1,n){
		read(a[i]),s[i]=s[i-1]+a[i];
		ans+=5*a[i]+x;
	}
	rep(k,1,n-1){
		ll res=k*x;
		for(int p,i=n,c=1;i;i=p,c++){
			p=max(i-k,0);
			res+=max(5,c*2+1)*(s[i]-s[p]);
			if(res>ans) break;
		}
		ans=min(ans,res);
	}
	cout<<ans+1ll*n*x<<endl;
	return 0;
}