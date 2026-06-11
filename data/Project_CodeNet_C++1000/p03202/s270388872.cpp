#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define qwq(x) cout<<"# "<<#x<<" = "<<x<<endl;
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

const int N=200005;
int a[N],n;

int chk(int c){
	static int x[N],y[N];
	int k=0;
	per(i,n,1){
		while(k&&x[k]>a[i])k--;
		int now=a[i];
		while(k&&x[k]==now&&y[k]==c-1)
			now--,k--;
		if(k&&x[k]==now)y[k]++;
		else x[++k]=now,y[k]=1;
		if(now!=a[i]&&a[i-1]==now)i--;
	}
	return x[1]>=1||x[1]==0&&k==1;
}

int main(){
	read(n);
	int flag=0;
	rep(i,1,n){
		read(a[i]);
		if(a[i]<=a[i-1])flag=1;
	}
	if(!flag){
		puts("1");
		return 0;
	}
	int l=2,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(chk(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}