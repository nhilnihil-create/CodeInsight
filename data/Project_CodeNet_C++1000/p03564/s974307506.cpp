#include <bits/stdc++.h>
#define rep(i,a,b) for(long long i = a; i < b; i++)
#define dump(a) for(auto x : a) cout << x << " "; cout << "\n"
#define print(a) cout << a << "\n"
#define debug(x) std::cerr<<#x<<": "<<x<<"\n"
#define debug2(x,y) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<"\n"
#define debug3(x,y,z) std::cerr<<#x<<": "<<x<<", "<<#y<<": "<<y<<", "<<#z<<": "<<z<<"\n"

using namespace std;
typedef long long ll;
using vi   = vector<int>;
using vll  = vector<ll>;
using vs   = vector<string>;
using vvi  = vector<vector<int>>;
using vvll = vector<vector<ll>>;
using vvs  = vector<vector<string>>;

const static string el = "\n";

int main()
{
  int _min = INT_MAX;
  int n,k;cin>>n>>k;
  rep(bits,1,(1<<n)) {
    ll tmp=1;
    rep(i,0,n) {
      int mask = 1<<i;
      if (bits&mask) tmp*=2; // 1(true)なら2倍 0(false)なら+kする;
      else tmp+=k;
    }
    if(tmp<_min) _min=tmp;
  }
  print(_min);
  return 0;
}