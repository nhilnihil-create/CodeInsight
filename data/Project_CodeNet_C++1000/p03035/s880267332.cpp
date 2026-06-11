#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;
const double e = 0.000000001;

int main(){
  ll a,b; cin >> a >> b;
  if(a>=13) cout << b;
  else if(a>=6) cout << b/2;
  else cout << 0; 
  return 0;
}
