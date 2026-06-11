#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)%s
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;
int n,Q;
char S[1000005];
int main(){
	scanf("%d%s",&n,S+1);
	scanf("%d",&Q);
	while (Q--){
		int k,laM=0,SD=0,SM=0;
		scanf("%d",&k);
		ll ans=0,sum=0;
		For(j,1,n){
			if (j>k){
				if (S[j-k]=='D') SD--,sum-=SM;
				if (S[j-k]=='M') SM--;
			}
			if (S[j]=='D') SD++;
			if (S[j]=='M') SM++,sum+=SD;
			if (S[j]=='C') ans+=sum; 
		}
		printf("%lld\n",ans);
	}
} 