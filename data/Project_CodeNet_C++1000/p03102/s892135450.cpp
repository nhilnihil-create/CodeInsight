#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int n,m,c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for(int i=0;i<m;i++){
    cin >> b.at(i);
  }
  vector<vector<int>> data(n, vector<int>(m));
  int ans=0;
  for (int i = 0; i < n; i++) {
    int sum=0;
    for (int j = 0; j < m; j++) {
      cin >> data.at(i).at(j);
      sum=sum+(data.at(i).at(j))*b.at(j);
    }
    if(sum+c>0)
    ans++;
  }
  cout << ans << endl;
}

