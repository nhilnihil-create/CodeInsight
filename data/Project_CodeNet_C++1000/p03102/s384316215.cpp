#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int n,m,c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for(int i=0;i<m;i++){
    cin >> b.at(i);
  }
  vector<vector<int>> data(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    int sum=0;
    for(int j=0;j<m;j++){
      sum+=(data.at(i).at(j))*b.at(j);
    }
    if(sum+c>0)
    ans++;
  }
  cout << ans << endl;
}

