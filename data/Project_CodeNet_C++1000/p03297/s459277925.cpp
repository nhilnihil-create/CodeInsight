#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln =  '\n';

const int mx=200010;
const ll mod=1e9+7;

ll gcd(ll a, ll b){ return b ? gcd(b,a%b):a; }

int main(){
  int q;
  cin >> q;
while(q--){
  ll a,b,c,d;
  cin >> a >> b >> c >> d;
  if(b>a){ cout << "No" << ln; continue; }
  if(b>d){ cout << "No" << ln; continue; }
  if(c>=b){ cout << "Yes" << ln; continue; }
  ll g = gcd(b,d);
  ll tmp = a%g + b -g;
  if(tmp>c){ cout << "No" << ln; continue; }
  cout << "Yes" << ln;
}
  return 0;
}