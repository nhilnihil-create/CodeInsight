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

int n,q;
string s,a;
vi b;

int f(){
	int l=-1,r=n;
	while(r-l>1){
		int m=(l+r)/2,x=m;
		for(int i=0;i<q;i++){
			if(s[x]==a[i]) x+=b[i];
			if(x==n||x==-1) break;
		}
		if(x==-1) l=m;
		else r=m;
	}
	reverse(s.begin(),s.end());
	for(int i=0;i<q;i++) b[i]*=-1;
	return l;
}

int main(){
	cin>>n>>q>>s;
	a=string(q,'.');
	b=vi(q,1);
	for(int i=0;i<q;i++){
		char c;
		cin>>a[i]>>c;
		if(c=='L') b[i]=-1;
	}
	cout<<n-2-f()-f()<<endl;
}