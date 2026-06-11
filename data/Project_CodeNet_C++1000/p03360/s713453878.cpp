#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main() {
  int abc[3];
  rep(i,3) cin>>abc[i];
  sort(abc,abc+3);
  int k;
  cin>>k;
  cout<<abc[0]+abc[1]+abc[2]*pow(2,k)<<endl;
  return 0;
}