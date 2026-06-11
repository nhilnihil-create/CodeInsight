#include<bits/stdc++.h>
#define fi first
#define se second
#define Mp make_pair
#define pb push_back
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
const int INF = 0x3f3f3f3f, nINF = 0xcfcfcfcf, INFMEM = 0x3f, nINFMEM = 0xcf;
const int PR1 = 1e6 + 3, PR2 = 1e9 + 7;
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int N = 1e5+3;
int n,a[N],b[N],sum[N*4],ans;
#define lowbit(x) (x)&-(x)
void modify(int x){
	for(;x<=N*4;x+=lowbit(x)) sum[x]++;
}
int query(int x){
	int ret=0; for(;x;x-=lowbit(x)) ret+=sum[x]; return ret;
}

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	int l=0,r=INF,mid;
	while(l<=r){
		mid=(l+r)>>1;
		ll cnt=0;
		{//calc cnt
			memset(sum,0,sizeof(sum));
			modify(n+1);
			rep(i,1,n) {
				b[i]=b[i-1]+(a[i]>=mid?1:-1);
				cnt+=query(b[i]+n+1); modify(b[i]+n+1);
			}
		}
		if(cnt>=(ll)n*(n+1)/2-cnt) ans=mid, l=mid+1; else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}