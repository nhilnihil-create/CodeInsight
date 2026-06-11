#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=100000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};


int main() {

	ll n,p;

	cin>>n>>p;

	ll o=1;
	ll d=0;
	if(n==1){
		cout<<p<<endl;
		return 0;
	}

	for(ll i=1000000; i>=2; i--){
		d=1;
		for(ll j=1; j<n+1&&d<=p; j++){
			d*=i;
			if(p%d>0){
				break;
			}
		}
		if(p%d==0){
			o=i;
			cout<<o<<endl;
			return 0;
		}

	}
	cout<<"1"<<endl;
	return 0;
}
