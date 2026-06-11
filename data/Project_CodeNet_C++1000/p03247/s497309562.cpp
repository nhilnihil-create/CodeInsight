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
const int maxn=1e5+10;
int n;
typedef pair<ll,ll> pii;
pii a[1010];
ll d[45],k=31;
int cmp(ll a,ll b){
	return a>b;
}
void solve(ll x,ll y){
	char s[1010]={0};
	for(int i=0;i<k;i++){
		ll l=abs(x+d[i])+abs(y),r=abs(x-d[i])+abs(y);
		ll p=abs(x)+abs(y+d[i]),u=abs(x)+abs(y-d[i]);
		if(l<=r&&l<=p&&l<=u){
			x+=d[i];
			s[i]='L';
		}else if(r<=l&&r<=p&&r<=u){
			x-=d[i];
			s[i]='R';
		}else if(p<=l&&p<=r&&p<=u){
			y+=d[i];
			s[i]='D';
		}else if(u<=l&&u<=r&&u<=p){
			y-=d[i];
			s[i]='U';
		}
	}
	//cout<<x<<" "<<y<<endl;
	cout<<s<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	//freopen("in","r",stdin);
	cin>>n>>a[1].fi>>a[1].se;
	int o=abs((a[1].fi+a[1].se)%2);
	for(int i=2;i<=n;i++){
		cin>>a[i].fi>>a[i].se;
		if(abs((a[i].fi+a[i].se)%2)!=o){
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=0;i<=30;i++){
		d[i]=(1ll<<i);
	}
	if(o==0){
		d[k++]=1;
	}
	sort(d,d+k,cmp);
	cout<<k<<endl;
	for(int i=0;i<k;i++){
		cout<<d[i]<<" "; 
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		solve(a[i].fi,a[i].se);
	}
	return 0;
}
