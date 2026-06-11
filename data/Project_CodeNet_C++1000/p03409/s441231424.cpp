#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

const long long mod = 1e9+7;

bool compare_by_second(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<pair<int, int>> red(N), blue(N);
  vector<bool> judge(N, true);
  for(int i = 0; i < N; i++) {
    cin >> red[i].first >> red[i].second;
  }
  for(int i = 0; i < N; i++) {
    cin >> blue[i].first >> blue[i].second;
  }
  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end(), compare_by_second);

  int ans = 0;
  for(int i = 0; i < N; i++) {
    int tmp = -1;
    for(int j = 0; j < N; j++) {
      if(judge[j] && red[j].first < blue[i].first && red[j].second < blue[i].second) {
        tmp = j;
      }
    }
    if(tmp != -1) {
      judge[tmp] = false;
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
