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
	int g,r,b,N;
  in(r>>g>>b>>N);
  int a = N/r;
  int d = N/g;
  int ans = 0;
  for(int i=0;i<=a;i++){
   for(int j=0;j<=d;j++){
    if((N-i*r-j*g)>=0&&(N-i*r-j*g)%b==0)ans++;
   }
  }
  out(ans);
}
  