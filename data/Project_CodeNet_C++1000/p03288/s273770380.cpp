#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int r;
  cin>>r;
  if(r<1200) cout<<"ABC"<<endl;
  else if(r<2800) cout<<"ARC"<<endl;
  else cout<<"AGC"<<endl;
  return 0;
}
