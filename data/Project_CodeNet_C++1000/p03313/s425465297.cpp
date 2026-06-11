#include<bits/stdc++.h>
using namespace std;
#define maxn 600020
#define rep(i,l,r) for(register int i = l ; i <= r ; i++)
#define repd(i,r,l) for(register int i = r ; i >= l ; i--)
#define rvc(i,S) for(register int i = 0 ; i < (int)S.size() ; i++)
#define rvcd(i,S) for(register int i = ((int)S.size()) - 1 ; i >= 0 ; i--)
#define fore(i,x)for (register int i = head[x] ; i ; i = e[i].next)
#define pb push_back
#define prev prev_
#define stack stack_
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pr;

int a[maxn],f[maxn],g[maxn];
int n,S;

int main(){
	scanf("%d",&n);
	S = (1 << n) - 1;
	rep(i,0,S) scanf("%d",&f[i]) , g[i] = -inf;
	rep(i,0,n - 1){
		rep(j,0,S){
			if ( j & (1 << i) ){
				if ( f[j] < f[j ^ (1 << i)] ){
					g[j] = f[j] , f[j] = f[j ^ (1 << i)];
					if ( g[j] < g[j ^ (1 << i)] ) g[j] = g[j ^ (1 << i)];
				}
				else if ( g[j] < f[j ^ (1 << i)] ) g[j] = f[j ^ (1 << i)];
			}
		}
	}
/*	rep(j,0,S){
		cout<<j<<" "<<f[j]<<" "<<g[j]<<endl;
	}*/
	rep(i,1,S){
		int pre = 0,ans = f[i] + g[i];
		repd(j,n - 1,0){
			if ( i & (1 << j) ){
				ans = max(ans,f[pre | ((1 << j) - 1)] + g[pre | ((1 << j) - 1)]);
				pre |= 1 << j;
			}
		}
		printf("%d\n",ans);
	}
}
