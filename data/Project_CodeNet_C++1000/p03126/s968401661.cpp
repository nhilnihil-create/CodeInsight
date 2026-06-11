#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> k(n);
  vector<vector<int>> a;
  for (int i=0 ; i<n ; i++){
    cin >> k.at(i);
    vector<int> b(k.at(i));
    for (int j=0 ; j<k.at(i) ; j++)
      cin >> b.at(j);
    a.push_back(b);
  }
  
  vector<int> like(m, 0);
  
  for (int i=0 ; i<n ; i++){
    for (int j=0 ; j<k.at(i) ; j++){
      like.at(a.at(i).at(j) - 1)++;
    }
  }
  
  int ans = 0;
  for (int i=0 ; i<m ; i++){
    if (like.at(i) == n)
      ans++;
  }
  
  cout << ans << endl;
}