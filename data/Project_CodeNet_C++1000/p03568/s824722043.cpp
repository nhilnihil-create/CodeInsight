#include <bits/stdc++.h>
using namespace std;
#define itn int
#define nibu(K,x) binary_search(K.begin(),K.end(),x)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define si(x) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define out(x) cout<<x<<endl
#define in(x) cin>>x
#define maxx(a,b,c) max(a,max(b,c))
#define minn(a,b,c) min(a,min(b,c))
using ll = long long;
using pll = pair<ll,ll>;
using psi = pair<string,int>;
using pis = pair<int,string>;
using vl = vector<ll>;
using vs = vector<string>;


int main() {
	itn N;
  in(N);
  vl A(N);
        rep(i,N) in(A[i] ) ;
  ll ans = pow(3,N);
  int s = 1;
  rep(i,N){
   if(A[i] %2 == 0) s *= 2;
  }
  out(ans - s);
}