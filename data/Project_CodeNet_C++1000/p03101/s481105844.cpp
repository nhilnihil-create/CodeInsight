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
  ll H,W,h,w; cin >> H >> W >> h >> w;
  cout << H*W-(H*w+W*h-h*w);
  return 0;
}
