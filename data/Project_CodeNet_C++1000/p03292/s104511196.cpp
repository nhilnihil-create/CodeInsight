#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); ++i)
#define rep1(i,n) for (int i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;
const double e = 0.000000001;
int main(){
  ll a,b,c; cin >> a >> b >> c;
  cout << min(abs(a-b)+abs(b-c), min(abs(b-c)+abs(c-a),abs(c-a)+abs(a-b)));
  return 0;
}
