#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  set<string> setS;
  map<string, vector<pair<int, int>>> mapS;
  
  for(int i=0; i<n; i++)
  {
    string s;
    int p;
    cin >> s >> p;
    setS.insert(s);
    mapS[s].push_back({-1 * p, i + 1});
  }
  
  for(auto s:setS)
  {
    vector<pair<int,int>> v = mapS[s];
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
      cout << v[i].second << endl;
  }
  
  return 0;
}