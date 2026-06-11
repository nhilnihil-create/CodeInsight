#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int a,b,x;
  cin>>a>>b>>x;
  if(a<=x && x<=a+b) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
