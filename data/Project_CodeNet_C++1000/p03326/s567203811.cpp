#include <bits/stdc++.h>

#define rep(i, n) for (ll i=0;i<(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using namespace std;
//using ll=long long;
typedef long long ll;
typedef pair<ll, ll> pi;



int main(){
  ll n,m;
  cin>>n>>m;

  ll x[n];
  ll y[n];
  ll z[n];

  rep(i,n){
    cin >>x[i]>>y[i]>>z[i];
  }

  
  ll xxi,yyi,zzi;
  ll xx,yy,zz;

  ll ans = 0;
  
  rep(xi,2){
    rep(yi,2){
      rep(zi,2){
	priority_queue<ll> p;
	ll tmp = 0;
	rep(i, n){

	  if (xi==0) xxi = -1; else xxi=1;
	  if (yi==0) yyi = -1; else yyi=1;
	  if (zi==0) zzi = -1; else zzi=1;
	  xx = x[i]*xxi;
	  yy = y[i]*yyi;
	  zz = z[i]*zzi;

	  p.push(xx+yy+zz);
	    
	  }

	rep(j,m){
	  //cout << p.top()<<endl;
	  tmp += p.top();
	  p.pop();
	}
	chmax(ans, tmp);
	
      }
    }
  }


  
  cout << ans << endl;

}
