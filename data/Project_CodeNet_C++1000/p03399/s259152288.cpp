#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  cout<<min(a,b)+min(c,d)<<endl;
  return 0;
}
