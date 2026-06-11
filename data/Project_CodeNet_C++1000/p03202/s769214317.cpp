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

int n;
vi a;

bool f(int m){
	stack<P> st;
	st.push({0,a[0]});
	for(int i=1;i<n;i++){
		if(a[i-1]<a[i]) st.push({0,a[i]-a[i-1]});
		else{
			int t=0,L=a[i-1];
			while(L>a[i]){
				P p=st.top();st.pop();
				L-=p.second;
				if(L<a[i]) st.push({p.first,a[i]-L});
			}
			while(!st.empty()){
				P p=st.top();st.pop();
				if(p.first<m-1){
					p.second--;
					if(p.second) st.push(p);
					st.push({p.first+1,1});
					if(t) st.push({0,t});
					break;
				}
				t+=p.second;
			}
			if(st.empty()) return 0;
		}
	}
	return 1;
}

int main(){
	cin>>n;
	a=vi(n);
	for(auto &i:a) cin>>i;
	int l=0,r=n;
	while(r-l>1){
		int m=(l+r)/2;
		if(f(m)) r=m;
		else l=m;
	}
	cout<<r<<endl;
}