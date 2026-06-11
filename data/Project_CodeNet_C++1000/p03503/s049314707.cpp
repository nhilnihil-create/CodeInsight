#include<iostream>
#include<algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;
typedef long long ll;
const ll INF=1e9+7;

ll max(ll a,ll b){
	if(a>b)return a;
	return b;
}

int main(){
	int n;
	cin>>n;
	int f[n][5][2],p[n][11];
	rep(i,n){
		rep(j,5){
			rep(k,2){
				cin>>f[i][j][k];
			}
		}
	}
	rep(i,n){
		rep(j,11){
			cin>>p[i][j];
		}
	}
	ll ans=-INF;
	loop(i,1,1<<10){
		int hmt[n];
		fill(hmt,hmt+n,0);
		rep(k,n){
			rep(j,10){
				int dow=j/2,time=j%2,josino=i&(1<<j);
				if(f[k][dow][time]&&josino)hmt[k]++;
			}
		}
		ll sum=0;
		rep(k,n){
			sum+=p[k][hmt[k]];
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
