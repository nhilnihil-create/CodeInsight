#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
ll A[200005], psum[200005];
int main(){
	int N; scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%lld",A+i);
		psum[i]=psum[i-1]+A[i];
	}
	ll ans=1e18,l,r;
	for(int i=2;i<N-1;i++){
		l=0,r=i;
		while(l+1<r){
			ll mid=l+r>>1;
			if(psum[mid] < psum[i]-psum[mid]) l=mid;
			else r=mid;
		}
		pair<ll,ll> a[2]={{psum[l],psum[i]-psum[l]},{psum[r],psum[i]-psum[r]}};
		for(int j=0;j<2;j++){
			if(a[j].first>a[j].second) swap(a[j].first,a[j].second);
		}
		l=i,r=N;
		while(l+1<r){
			ll mid=l+r>>1;
			if(psum[mid]-psum[i] < psum[N]-psum[mid]) l=mid;
			else r=mid;
		}
		pair<ll,ll> b[2]={{psum[l]-psum[i],psum[N]-psum[l]},{psum[r]-psum[i],psum[N]-psum[r]}};
		for(int j=0;j<2;j++){
			if(b[j].first>b[j].second) swap(b[j].first,b[j].second);
		}
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				ans=min(ans,max(a[j].second,b[k].second) - min(a[j].first,b[k].first));
			}
		}
	}
	printf("%lld",ans);
}