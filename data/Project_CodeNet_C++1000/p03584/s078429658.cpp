#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

lli n,k;
vll a,b;
lli ans = 0;

int main(){
  cin >> n >> k;
  a = vll(n);
  b = vll(n);
  for(lli i = 0;i < n;i++) cin >> a[i] >> b[i];
  for(lli i = 0,j = 1;i < 30;i++,j <<= 1){
    if(k&j){
      lli s = (k^j)|(j-1);
      lli t = ~s;
      lli mem = 0;
      for(lli i = 0;i < n;i++){
        if((t&a[i]) == 0) mem += b[i];
      }
      ans = max(ans,mem);

    }
  }
  lli t = ~k;
  lli mem = 0;
  for(lli i = 0;i < n;i++){
    if((t&a[i]) == 0) mem += b[i];
  }
  ans = max(ans,mem);
  cout << ans << endl;
}
