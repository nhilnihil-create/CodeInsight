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

ll f(ll x){
	ll t=0;
	while(x) t+=x%10,x/=10;
	return t;
}

int k;

int main(){
	cin>>k;
	vl a;
	ll t=1;
	for(int i=0;i<15;i++){
		for(int j=2;j<=150;j++) a.push_back(t*j-1);
		t*=10;
	}
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	ll S=a.size();
	for(int i=0;k;i++){
		bool B=0;
		for(int j=i+1;j<S;j++) if(a[i]*f(a[j])>a[j]*f(a[i])) B=1;
		if(!B){
			cout<<a[i]<<endl;
			k--;
		}
	}
}