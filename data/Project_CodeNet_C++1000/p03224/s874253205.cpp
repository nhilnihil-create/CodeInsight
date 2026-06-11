#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n;
vvi a;

int main(){
	cin>>n;
	for(ll k=1;k<100000;k++) if(k*(k-1)/2==n){
		cout<<"Yes"<<endl;
		cout<<k<<endl;
		a=vvi(k);
		int t=1;
		for(int i=0;i<k;i++) for(int j=i+1;j<k;j++){
			a[i].push_back(t);
			a[j].push_back(t);
			t++;
		}
		for(int i=0;i<k;i++){
			int N=a[i].size();
			cout<<N;
			for(int j=0;j<N;j++) cout<<' '<<a[i][j];
			cout<<endl;
		}
		return 0;
	}
	cout<<"No"<<endl;
}