#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  map<string, vector<P>> mp;
  rep(i, n){
    string s;
    int p;
    cin >> s >> p;
    if (mp.find(s) != mp.end()){
      mp[s].push_back(P(p, i+1));
    }
    else{
      mp[s] = vector<P>{P(p, i+1)};
    }
  }
  
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    sort(mp[itr->first].rbegin(), mp[itr->first].rend());
    for (P x : mp[itr->first]){
      cout << x.second << endl;
    }
  }
  
  return 0;
}