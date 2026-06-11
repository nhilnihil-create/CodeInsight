#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, H;
  cin >> N >> H;
  vector<pair<int,int>> dam(2*N);
  for (int i = 0; i < 2*N; i++) {
    int x;
    cin >> x;
    dam[i] = make_pair(x,i);
  }
  
  sort(dam.begin(), dam.end(), greater<pair<int,int>>());
  int AC = 0;
  int i = 0;
  while (H > 0) {
    if (dam[i].second % 2 == 1) {
      H -= dam[i].first;
      AC += 1;
      i++;
    }
    else {
      AC += (H-1) / dam[i].first + 1;
      break;
    }
  }
  cout << AC << endl;
}