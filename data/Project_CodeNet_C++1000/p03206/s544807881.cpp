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
  int d; cin >> d;
  string ans = "Christmas";
  rep(i,(25-d)){
    ans += " Eve";
  }
  cout << ans;
  return 0;
}
