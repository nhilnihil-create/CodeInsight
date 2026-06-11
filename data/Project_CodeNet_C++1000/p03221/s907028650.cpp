#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<pair<pair<int,int>, int>> city(M);
  vector<pair<int, int>> ans(M);
  
  for (int i = 0; i < M; i++) {
    int P, Y;
    cin >> P >> Y;
    pair<int, int> p = make_pair(P,Y);
    city[i] = make_pair(p, i);
    
    pair<int, int> q = make_pair(P, 0); // 0 は適当な数
    ans[i] = q; // 市i の 所属する県だけチェックしておく．
  }

  sort(city.begin(), city.end());
  
  int lower = 1;
  vector<pair<int,int>> junban(M);
  
  for (int i = 0; i < M; i++) {
     if (city[i].first.first == city[i+1].first.first) {
      ans[city[i].second].second = lower;
      lower++;
     } else {
      pair<int, int> q = make_pair(city[i].second, lower);
      ans[city[i].second].second = lower;
      lower = 1;
     }
      
  }
  for (int i = 0; i < M; i++) {
    printf("%06d", ans[i].first);
    printf("%06d", ans[i].second);
    cout << endl;
      
      
  }
  
  
}