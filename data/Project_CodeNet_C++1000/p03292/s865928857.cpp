#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  vector<int> a(3);
  rep(i,3) cin>>a[i];
  sort(a.begin(),a.end());
  cout<<a[2]-a[0]<<endl;
}