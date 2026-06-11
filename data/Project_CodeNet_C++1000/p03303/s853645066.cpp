#include<bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define per(i,n) for(int i=n-1;i>=0;++i)
#define rep1(i,n) for(int i=1; i<=n; ++i)
#define per1(i,n) for(int i=n; i>=1; ++i)
#define debug cout << "line : " << __LINE__ << " debug" << endl
#define Dcout(N) cout << setprecision(20) << N << endl
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() ) //被り削除
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF 1e9
#define MOD 1000000007
typedef long long ll;
//------------------------------------------------------------------------

ll gcd(ll a, ll b) {return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >> s;
  int w; cin >> w;
  rep(i,s.size()){
    if(i%w==0) cout << s[i];
  }

  cout << endl;

  return 0;
}
