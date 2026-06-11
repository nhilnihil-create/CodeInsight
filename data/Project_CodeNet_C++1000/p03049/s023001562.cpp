#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  int a = 0, b = 0, ans = 0, ab = 0;
  rep(i, n) {
    string s;
    cin >> s;
    rep(j, s.length() - 1) {
      if(s[j] == 'A' && s[j + 1] == 'B') ++ans;
    }
    if(s[0] == 'B' && s.back() == 'A') ++ab;
    else if(s[0] == 'B') ++b;
    else if(s.back() == 'A') ++a;
  }
  if(a == 0 && b == 0) {
    ans += max(0, ab - 1);
  } else {
    ans += ab + min(a, b);
  }
  cout << ans << endl;
};