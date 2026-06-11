#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n;
  map<string, int> mp;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    mp[s]++;
  }
  
  cin >> m;
  for(int i = 0; i < m; i++){
    string s;
    cin >> s;
    mp[s]--;
  }
  int ans = -10000007;
  for(pair<string, int> x : mp){
    ans = max(ans, x.second);
  }
  cout << max(ans, 0) <<endl;
}