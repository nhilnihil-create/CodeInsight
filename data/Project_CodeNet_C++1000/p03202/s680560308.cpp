#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=300005;
int n,a[N];
pii q[N];
bool check(int k){
	int top=1,S=a[1];
	q[1]=pii(a[1],1);
	For(i,2,n){
		if (S<a[i]){
			q[++top]=pii(a[i]-S,1);
			S=a[i];
			continue;
		}
		for (;S>a[i];){
			int dif=min(q[top].fi,S-a[i]);
			q[top].fi-=dif; S-=dif;
			if (!q[top].fi) --top;
		}
		for (;top&&q[top].se==k;--top)
			S-=q[top].fi;
		if (!top) return 0;
		if (q[top].fi==1) ++q[top].se;
		else{
			q[++top]=pii(1,0);
			q[top-1].fi--;
			q[top].se=q[top-1].se+1;
		}
		if (S<a[i]){
			q[++top]=pii(a[i]-S,1);
			S=a[i];
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int l=1,r=n,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1; 
	} 
	printf("%d\n",ans);
} 