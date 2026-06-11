#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
// typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 1000000007;
const lli e3 = 1 << 12;
const lli INF = 1ll << 63;

lli n;
lli a[e5];
lli l = 0;

bool solve(lli x){
  map<lli,lli> mem;
  for(lli i = 1;i <= n;i++){
    if(a[i] <= a[i-1]){
      lli y = mem[a[i]];
      mem.erase(mem.find(a[i]),mem.end());


      mem[a[i]] = y+1;
      // cerr << " " << a[i] << endl;
      //
      // for(auto x : mem){
      //   cerr << x.first << " " << x.second << endl;
      // }
      for(lli j = a[i];mem[j] >= x;j--){
        if(j <= 1) return false;
        mem[j] = 0;
        mem[j-1]++;
      }
    }
  }
  return true;
}

int main(){
  cin >> n;
  for(lli i = 1;i <= n;i++) cin >> a[i];
  for(lli i = 1;i <= n;i++){
    if(a[i-1] >= a[i]) break;
    if(i == n){
      cout << 1 << endl;
      return 0;
    }
  }
  lli top = n;
  lli bottom = 1;
  while(top-bottom > 1){
    lli middle = (top+bottom)/2;
    cerr << middle << endl;
    if(solve(middle)) top = middle;
    else bottom = middle;

  }
  cout << top << endl;

}
