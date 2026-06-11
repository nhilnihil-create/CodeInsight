#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main() {
  int a,b;
  cin>>a>>b;
  if(a<=b) cout<<a<<endl;
  else cout<<a-1<<endl;
  return 0;
}