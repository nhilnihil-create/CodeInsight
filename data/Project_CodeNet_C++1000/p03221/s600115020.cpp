#include <bits/stdc++.h>
using namespace std;

int main(){
  stringstream ss;
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> city(n + 1);
  vector<string> ans(m);
  for (int i = 0; i < m; i++)
  {
    int cnum, y;
    cin >> cnum >> y;
    pair<int, int> p(y, i);
    city.at(cnum).push_back(p);
  }
  
  for(int i = 1; i < n + 1; i++){
    sort(city.at(i).begin(), city.at(i).end());
    for(int j = 0; j < city.at(i).size(); j++){
      int ci = i, cj = j + 1;
      int idx = city.at(i).at(j).second;
      ss << setw(6) << setfill('0') << ci << setw(6) << setfill('0') << cj;
      string id = ss.str();
      ss.str("");
      ss.clear(stringstream::goodbit);
      ans.at(idx) = id;
      
      
      // cout << city.at(i).at(j).first << " " << city.at(i).at(j).second << endl;
    }
  }
  
  for(int i = 0; i < m; i++){
    cout << ans.at(i) << endl;
  }
  
}