#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;cin>>n;
  string s;cin>>s;
  int an[26];rep(i,26)an[i]=1;
  for (auto c:s) {
    int i=c-'a';
    an[i]++;
  }
  ll cnt=1;
  ll MOD=1e9+7;
  rep(i,26) {
    cnt = (cnt * an[i]) % MOD;
  }
  cnt = (cnt+MOD-1)%MOD;
  cout<<cnt;
}
