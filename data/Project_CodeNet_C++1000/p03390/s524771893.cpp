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

lli q;
vll a,b;

int main(){
  cin >> q;
  for(lli i = 0;i < q;i++){
    lli a,b;
    cin >> a >> b;
    lli c = a*b;
    lli d = 0;
    for(lli bit = 1ll << 30;bit > 0;bit >>= 1){
      if((d|bit)*(d|bit) < c) d |= bit;
    }
    lli sft = 0;
    // cout << d << endl;
    if(d*(d+1) >= c)sft--;
    if(a <= d) sft--;
    if(b <= d) sft--;
    cout << d*2+sft << endl;
  }
  return 0;
}
