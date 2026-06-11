#include<bits/stdc++.h>
#define fi first
#define se second
#define bug cout<<"--------------"<<endl
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-6;
const int inf=1e9;
const ll llf=1e18;
const int mod=1e9+7;
const int maxn=2e5+10;
int n;
int a[maxn],b[maxn],a1[maxn],b1[maxn];
int main(){
	ios::sync_with_stdio(false);
	//freopen("in","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	ll ans=0;
	for(int i=0;i<29;i++){
		for(int j=1;j<=n;j++){
			a1[j]=(a[j]%(1<<(i+1)));
			b1[j]=(b[j]%(1<<(i+1)));
		}
		sort(b1+1,b1+n+1);
		int t=(1<<i);
		ll ret=0;
		for(int j=1;j<=n;j++){
			ret+=lower_bound(b1+1,b1+n+1,2*t-a1[j])-lower_bound(b1+1,b1+n+1,t-a1[j]);
			ret+=lower_bound(b1+1,b1+n+1,4*t-a1[j])-lower_bound(b1+1,b1+n+1,3*t-a1[j]);
		}
		if(ret&1) ans|=(1<<i);
	}
	cout<<ans<<endl;
	return 0;
}
