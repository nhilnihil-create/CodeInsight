#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


bool compare_by_b(pair<int, pair<string, int>> a, pair<int, pair<string, int>> b) {
  if(a.second.first != b.second.first){
      return a.second.first < b.second.first;
  }else{
      return a.second.second < b.second.second;
      // cerr << "Some error" << endl;
      // return 1;
  }
}

int main() {
  int N;
  cin >> N;
  vector<pair<int, pair<string, int>>> restaurant(N);
  rep(i,N) {
    restaurant[i].first = i+1;
    cin >> restaurant[i].second.first >> restaurant[i].second.second;
    restaurant[i].second.second *= -1;
  }
  sort(restaurant.begin(), restaurant.end(), compare_by_b);
  rep(i,N) {
    // cout << restaurant[i].second.first << " " << restaurant[i].second.second << endl;
    cout << restaurant[i].first << endl;
  }
  return 0;
}