#include<bits/stdc++.h>
using namespace std;
int main(){
  int n; cin >> n;
  vector<pair<string, int>> card;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    bool flag = true;
    for(int j = 0; j < card.size(); j++){
      if(card.at(j).first == s){
        card.at(j).second++;
        flag = false;
        break;
      }
    }
    if(flag)
      card.push_back(make_pair(s,1));
  }
  int m; cin >> m;
  for(int i = 0; i < m; i++){
    string s; cin >> s;
    bool flag = true;
    for(int j = 0; j < card.size(); j++){
      if(card.at(j).first == s){
        card.at(j).second--;
        flag = false;
        break;
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < card.size(); i++){
    ans = max(ans,card.at(i).second);
  }
  cout << ans;
}
      