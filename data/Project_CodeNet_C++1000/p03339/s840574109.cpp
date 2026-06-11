#include<bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main(){
  int n; cin >> n;
  string s; cin >> s;
  vector<pair<int, int>> line(n + 1, make_pair(0, 0));
  for(int i = 0; i < n; ++i){
    if(s[i] == 'W') line[i + 1].first = 1;
    else line[i + 1].second = 1;
  }
  for(int i = 1; i < n + 1; ++i){
    line[i].first += line[i - 1].first;
    line[i].second += line[i - 1].second;
  }
  int min_turn = INF;
  for(int i = 1; i < n + 1; ++i){
    min_turn = min(min_turn, line[i -1].first - line[0].first + line[n].second - line[i].second );
  }
  cout << min_turn << endl;
}