#include <bits/stdc++.h>
using namespace std;
#define itn int
#define nibu(K,x) binary_search(K.begin(),K.end(),x)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define out(x) cout<<x<<endl
#define put(x) out(x)
#define in(x) cin>>x
#define maxx(a,b,c) max(a,max(b,c))
#define minn(a,b,c) min(a,min(b,c))
using ll = long long;
using vl = vector<ll>;
using vs = vector<string>;
const double pi = 3.14159265358979;
const ll mod = 1000000007;

int main() {
 int N,M,X,Y;
  in(N>>M>>X>>Y);
  vl x(N),y(M);
  rep(i,N) in(x[i]);
  rep(i,M)in(y[i]);
 sort(all(x));
  sort(all(y));
  bool f = false;
  for(int i=X+1;i<=Y;i++){
   if(x[N-1]<i&&i<=y[0]) f = true; 
  }
  if(f) out("No War");
  else out("War");
}