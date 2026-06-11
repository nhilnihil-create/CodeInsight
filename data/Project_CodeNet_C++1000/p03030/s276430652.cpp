#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  vector<tuple<string, int, int>> v;
  string city;
  int score;
  cin >> N;
  for(int i=0;i<N;i++) {
    cin >> city >> score;
    v.push_back(make_tuple(city,score, i));
  }
  
  sort(v.begin(), v.end(), [](const tuple<string, int, int>& t1, const tuple<string,int,int>& t2) {
    string city1;
    int score1;
    tie(city1, score1, ignore) = t1;
    
    string city2;
    int score2;
    tie(city2, score2, ignore) = t2;

    
    if (city1 < city2) return true;
    else if (city1 == city2) return score1 > score2;
    return false;
  });
  
  for(int i=0;i<N;i++) {
    cout << get<2>(v[i]) + 1<< endl;
  }
  
}