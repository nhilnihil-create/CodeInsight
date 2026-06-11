#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007
#define Vi vector<int>
#define Vl vector<long long>
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=10000000000000000001;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct edge{int to,cost;};
struct pos{
	int x,y,cost;
};

int main() {

	int a,b,c;
	ll x,y;
	cin>>a>>b>>c>>x>>y;
	if(a+b<=c*2)cout<<a*x+b*y<<endl;
	else{
		ll ans=0;
		if(x<=y){
			ans+=c*2*x;
			ans+=min(b*(y-x),c*2*(y-x));
		}else{
			ans+=c*2*y;
			ans+=min(a*(x-y),c*2*(x-y));
		}
		cout<<ans<<endl;
	}

	return 0;
}
