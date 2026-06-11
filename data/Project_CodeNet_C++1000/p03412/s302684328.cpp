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

lli n;
vll a,b;
vll s,t;
lli ans;

int main(){
  cin >> n;
  a = vll(n);b = vll(n);
  for(lli i = 0;i < n;i++) cin >> a[i];
  for(lli i = 0;i < n;i++) cin >> b[i];
  lli ub = max(*max_element(a.begin(),a.end()),*max_element(b.begin(),b.end()))*2;
  for(lli bit = 1;bit <= ub;bit <<= 1){
    s = a;t = b;
    bit <<= 1;
    for(lli i = 0;i < n;i++) s[i] %= bit,t[i] %= bit;
    bit >>= 1;
    sort(t.begin(),t.end());
    lli c = 0;
    for(lli i = 0;i < n;i++){
      c += lower_bound(t.begin(),t.end(),bit*2-s[i])-lower_bound(t.begin(),t.end(),bit*1-s[i]);
      c += lower_bound(t.begin(),t.end(),bit*4-s[i])-lower_bound(t.begin(),t.end(),bit*3-s[i]);
    }
    ans |= ((c%2)*bit);
  }
  cout << ans << endl;
}
