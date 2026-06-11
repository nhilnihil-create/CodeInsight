#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n;
  cin>>n;
  int ans=1;
  while(ans*ans<=n) ans++;
  ans--;
  cout<<ans*ans<<endl;
  return 0;
}
