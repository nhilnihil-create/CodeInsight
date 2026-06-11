#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int d;
  cin>>d;
  string ans="Christmas",eve=" Eve";
  rep(i,25-d) ans+=eve;
  cout<<ans<<endl;
  return 0;
}
