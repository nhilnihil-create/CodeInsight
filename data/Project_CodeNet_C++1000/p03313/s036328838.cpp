#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int>vi;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define fi first
#define se second
#define de(x) cout<<#x<<"="<<x<<"\n"
#define dd(x) cout<<#x<<"="<<x<<" "
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define lowbit(a) ((a)&-(a))
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
const int N=2e6+5;
pii f[N];
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	rep(i , 0 , 1<<n){
		scanf("%d",&a[i]);
		f[i].fi = a[i],f[i].se = -1;
	}
	rep(j , 0 , n)
		rep(i , 0 , 1<<n){
			if((i>>j)&1){
				int sta = i ^ (1<<j);
				if(f[i].fi < f[sta].fi){
					f[i].se = f[i].fi;
					f[i].fi = f[sta].fi;
					if(f[i].se < f[sta].se)
						f[i].se = f[sta].se; 
				}
				else if(f[i].se < f[sta].fi)
					f[i].se = f[sta].fi;
			}
		}
	int ans = 0;
	rep(i , 1 , 1<<n){
		ans = max(ans, f[i].fi + f[i].se);
		printf("%d\n",ans);
	}
	return 0;
}


