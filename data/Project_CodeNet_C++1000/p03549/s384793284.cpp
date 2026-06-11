#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main() {
  int n,m;
  cin>>n>>m;
  int revp=pow(2,m),t=m*1900+(n-m)*100;
  cout<<t*revp<<endl;
  return 0;
}