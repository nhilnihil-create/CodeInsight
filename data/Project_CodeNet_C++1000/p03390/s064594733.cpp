#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << (x) << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
using ll = long long;
ll mx(ll a,ll m){
	ll mx = max((a+1)*m,a+m);
	ll x = (a+m+1)/2;
	if(a+1<=x && x<=a+m) chmax(mx,x*(a+m+1-x));
	return mx;
}
int main(){
	int Q;
	cin>>Q;
	rep(qt,Q){
		ll a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		ll res = a-1;
		ll ub = b, lb = 0;
		while(ub-lb>1){
			ll m = (ub+lb)/2;
			if(mx(a,m) < a*b) lb = m;
			else ub = m;
		}
		res += lb;
		cout<<res<<endl;
	}
}
