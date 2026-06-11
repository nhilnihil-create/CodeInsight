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
const int N=100005;
ll D[N],S[N],SS[N];
int n,id[N],fa[N];
bool cmp(int x,int y){
	return D[x]<D[y];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&D[i]);
	For(i,1,n) id[i]=i,S[i]=1,SS[i]=0;
	sort(id+1,id+n+1,cmp);
	Rep(i,n,2){
		ll fv=D[id[i]]-n+2*S[id[i]];
		int l=1,r=i-1,ans=0;
		while (l<=r&&!ans){
			int mid=(l+r)/2;
			if (D[id[mid]]==fv)	ans=mid;
			else if (D[id[mid]]<fv) l=mid+1;
			else r=mid-1;
		}
		if (!ans) return puts("-1"),0;
		int fa=::fa[id[i]]=id[ans];
		S[fa]+=S[id[i]];
		SS[fa]+=SS[id[i]];
		SS[fa]+=S[id[i]];
	}
	if (SS[id[1]]!=D[id[1]]) return puts("-1"),0;
	For(i,2,n) printf("%d %d\n",fa[id[i]],id[i]);
}