#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main(){
	int n,m; cin>>n>>m;
	vector<pair<ll,ll>> vp(n);
	rep(i,n){
		int a,b; cin>>a>>b;
		vp[i]=make_pair(a,b);
	}
	sort(all(vp));
	int i=0;
	ll ans=0;
	while(m>0){
		if(m>=vp[i].second){
			ans+=vp[i].first*vp[i].second;
			m-=vp[i].second;
			i++;
		}else{
			ans+=vp[i].first*m;
			m=0;
		}
	}
	cout<<ans<<endl;
}