#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1e9+7;

int main() {
  int h,w,x,y;
  cin>>h>>w>>x>>y;
  cout<<h*w-h*y-w*x+x*y<<endl;
  return 0;
}