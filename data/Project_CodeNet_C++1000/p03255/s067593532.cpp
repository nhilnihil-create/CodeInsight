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
const lli mod = 998244353;
const lli e3 = 1 << 12;
const lli INF = 1ll << 63;

lli n,e;
lli x[e5];

lli solve(lli num){
  if(num == 0) return INF;
  lli ans = 0;
  for(lli i = 1;i <= num;i++){
    ans += x[n-i];
  }
  for(lli i = 1;i <= num;i++){
    lli j,k;
    for(j = n-num-i,k = 1;j >= 0;j-=num,k++){
      ans += (x[j+num]-x[j])*(k+1)*(k+1);
    }
    ans += x[j+num]*(k+1)*(k+1)+e;
  }
  return ans;
}

int main(){
  cin >> n >> e;
  for(lli i = 0;i < n;i++) cin >> x[i];
  // for(lli i = 1;i <= n;i++) cout << solve(i)+e*n << endl;
  lli top = n;
  lli bottom = 0;
  while(top-bottom > 1){
    lli middle = (top+bottom)/2;
    if(solve(middle+1) > solve(middle)) top = middle;
    else bottom = middle;
  }
  cout << solve(top)+e*n << endl;

}
