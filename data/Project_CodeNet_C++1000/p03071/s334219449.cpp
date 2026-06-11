#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;

int main(){
  ll a,b; cin >> a >> b;
  cout << max(2*a-1, max(a+b, 2*b-1));
  return 0;
}
