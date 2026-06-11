#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,ans = 1e5;
  cin >> n;
  rep(i,1,n){
    int a = i,b = n-i,sum = 0;
    string aa = to_string(a),bb = to_string(b);
    rep(j,0,aa.size()) sum += aa[j]-'0';
    rep(j,0,bb.size()) sum += bb[j]-'0';
    ans = min(ans,sum);
  }
  cout << ans << endl;
}