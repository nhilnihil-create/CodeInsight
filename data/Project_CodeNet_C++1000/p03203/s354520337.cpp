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
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int h,w,n;
vi a;

int main(){
	cin>>h>>w>>n;
	a=vi(h+1,w);
	a[h]=0;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[x-1]=min(a[x-1],y-1);
	}
	int t=0;
	for(int i=0;i<h;i++){
		int x=a[i+1];
		if(x<=t){
			cout<<i+1<<endl;
			break;
		}
		if(t+1<x) t++;
	}
}