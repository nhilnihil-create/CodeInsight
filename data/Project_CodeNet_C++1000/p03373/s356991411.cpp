#include <bits/stdc++.h>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
#define traceV(v) for(auto x:v)cout<<x<<" ";cout<<endl
#define traceM(mp) for(auto x:mp)cout<<x.first<<" "<<x.second<<endl

//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 2e+9 + 10;
typedef pair<ll, ll> P;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;

  ll res = 5000000000*2;     // MAX
  rep(i, max(X,Y)+1) {    // A: a, B: b, AB: i*2
    ll a = X-i, b = Y-i;
    if(a<0)a=0;
    if(b<0)b=0;
    res = min(res, A*a+B*b+C*(i*2));
  }
  cout << res << endl;


  return 0;
}
