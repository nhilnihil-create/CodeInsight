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
ll a[100001],b[100001],c[100001];
ll d[100001]={},ans[100001]={};
int n;

int main() {

	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n)cin>>b[i];
	rep(i,n)cin>>c[i];
	sort(c,c+n);
	sort(b,b+n);
	sort(a,a+n);
	rep(i,n){
		int left=0,right=n,mid;
		while(left<right){
			mid=(right+left)/2;
			if(a[mid]>=b[i])right=mid;
			if(a[mid]<b[i])left=mid+1;
		}
		d[i]=left;
		d[i]+=d[i-1];
	}
	rep(i,n){
		int l=0,r=n,m;
		while(l<r){
			m=(r+l)/2;
			if(b[m]>=c[i])r=m;
			if(b[m]<c[i])l=m+1;
		}
		ans[i]=d[l-1];
		ans[i]+=ans[i-1];
	}
	cout<<ans[n-1]<<endl;

	return 0;
}
