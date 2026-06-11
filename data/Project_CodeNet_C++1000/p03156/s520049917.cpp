#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long int li;
typedef long double lb;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define repr(i,j,n) for(ll i = j; i >= (n); i--)
#define all(x) (x).begin(),(x).end()
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const ll INF = 1LL<<60;

const int dx[]={0,-1,1,0},dy[]={-1,0,0,1};

int main(){

  ll n;cin>>n;
  ll a,b;cin>>a>>b;
  // ll p[n];rep(i,0,n)cin>>p[i];

  ll num[3];CLR(num,0);
  rep(i,0,n){
    ll p;cin>>p;

    if(p>=b+1)num[2]++;
    else if(a+1<=p&&p<=b)num[1]++;
    else num[0]++;

  }

  out(min({num[0],num[1],num[2]}));

  return 0;
}
