#include <bits/stdc++.h>
using namespace std;

using tiii = tuple<int, int, int>; //year, city, prefecture
using pii = pair<int, int>; //prefecture, rank

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<tiii> memo;
  for (int i = 1; i <= M; i++) {
    int p, y;
    cin >> p >> y;
    memo.push_back(make_tuple(y, i, p));
  }
  
  sort(memo.begin(), memo.end());
  
  pii ansMemo[M+1];
  map<int, int> prefectureRank;
  for (auto t: memo) {
    int year;
    int city;
    int prefecture;
    tie(year, city, prefecture) = t;
    
    ansMemo[city] = {prefecture, ++prefectureRank[prefecture]};
    
  }
  
  for (int i = 1; i <= M; i++) {
    string prefecture = to_string(ansMemo[i].first);
    string rank = to_string(ansMemo[i].second);
    
    cout << string(6-prefecture.size(), '0');
    cout << prefecture;
    cout << string(6-rank.size(), '0');
    cout << rank << endl;
  }
  
  return 0;
}