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
struct pos{
	int x,y,cost;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};

int main() {

	int n,a[12];

	cin>>n;

	ll k=1,t=1;
	for(int i=1; i<n+1; i++){
		cin>>a[i];
		if(a[i]%2==0)k*=2;
		t*=3;
	}
	cout<<t-k<<endl;
	return 0;
}
