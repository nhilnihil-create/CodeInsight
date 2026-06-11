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
const ll INF=100000000001;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct edge{int to,cost;};
struct pos{
	int x,y,cost;
};

int a[100001],b[100001];
Pi d[100001]={};

int main() {

	int n,m;
	cin>>n>>m;
	rep(i,m){
		cin>>a[i]>>b[i];
		d[i].first=a[i];
		d[i].second=b[i];
	}
	sort(d,d+m);
	int ans=1,mi=d[0].second-1;
	for(int i=1; i<m; i++){
		if(mi<d[i].first){
			ans++;
			mi=d[i].second-1;
		}
		mi=min(mi,d[i].second-1);
	}
	cout<<ans<<endl;

	return 0;
}
