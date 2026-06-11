#include<bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=998244353;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-9;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	int n;cin>>n;
	ll l[100010],r[100010];
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i];
	}
	sort(l,l+n,greater<ll>());
	sort(r,r+n);
	ll s=0,ans=0;
	for(int i=0;i<n;i++){
		s+=l[i];
		ans=max(s,ans);
		s-=r[i];
		ans=max(s,ans);
	}
	s=0;
	for(int i=0;i<n;i++){
		s-=r[i];
		ans=max(s,ans);
		s+=l[i];
		ans=max(s,ans);
	}
	cout<<ans*2<<endl;
	return 0;
}
