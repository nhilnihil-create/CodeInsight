#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

bool cmp(pair<int,int> a, pair<int,int> b) { 
  return a.second < b.second; 
}

int main() {
  int n;
  cin >> n;
  vector<P> red(n);
  vector<P> blue(n);

  for (int i = 0; i < n; i++) {
    cin >> red[i].first >> red[i].second;
  }

  for (int i = 0; i < n; i++) {
    cin >> blue[i].first >> blue[i].second;
  }

  sort(red.begin(), red.end(), cmp);
  reverse(red.begin(), red.end());

  sort(blue.begin(), blue.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < red.size(); j++) {
      if (blue.at(i).first > red.at(j).first && blue.at(i).second > red.at(j).second) {
        red.erase(red.begin()+j);
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}