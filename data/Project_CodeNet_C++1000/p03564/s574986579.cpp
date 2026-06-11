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
  int result = 1,n,k;cin>>n>>k;
  rep(i,0,n) {
    if (result>=k) result+=k;
    else result*=2;
  }
  print(result);
  return 0;
}