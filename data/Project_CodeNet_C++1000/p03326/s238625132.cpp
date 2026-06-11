#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,m;
  cin >> n >> m;
  vector<ll>d1(n),d2(n),d3(n),d4(n),d5(n),d6(n),d7(n),d8(n);
  rep(i,0,n){
    ll x,y,z;
    cin >> x >> y >> z;
    d1[i] = x+y+z;
    d2[i] = x+y-z;
    d3[i] = x-y+z;
    d4[i] = -x+y+z;
    d5[i] = x-y-z;
    d6[i] = -x+y-z;
    d7[i] = -x-y+z;
    d8[i] = -x-y-z;
  }
  sort(d1.begin(),d1.end());
  sort(d2.begin(),d2.end());
  sort(d3.begin(),d3.end());
  sort(d4.begin(),d4.end());
  sort(d5.begin(),d5.end());
  sort(d6.begin(),d6.end());
  sort(d7.begin(),d7.end());
  sort(d8.begin(),d8.end());
  ll s1 = 0,s2 = 0,s3 = 0,s4 = 0,s5 = 0,s6 = 0,s7 = 0,s8 = 0;
  rep(i,0,m){
    s1 += d1[n-1-i];
    s2 += d2[n-1-i];
    s3 += d3[n-1-i];
    s4 += d4[n-1-i];
    s5 += d5[n-1-i];
    s6 += d6[n-1-i];
    s7 += d7[n-1-i];
    s8 += d8[n-1-i];
  }
  ll ans = max(s1,s2);
  ans = max(ans,s3);ans = max(ans,s4);ans = max(ans,s5);ans = max(ans,s6);
  ans = max(ans,s7);ans = max(ans,s8);
  cout << ans << endl;
}