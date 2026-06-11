#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> o;
  vector<pair<int, int>> b(n);
  for(int i = 0; i < n; i++) scanf("%d", &b[i].first), b[i].second = i + 1;
  for(int i = 0; i < n; i++) {
    int j;
    for(j = n - 1; j >= 0; j--) {
      if(b[j].first == b[j].second) {
        o.push_back(b[j].first);
        b[j].second = -1;
        for(int k = j + 1; k < n; k++) b[k].second--;
        break;
      }
    }
    if(j == -1) {
      printf("-1\n");
      return 0;
    }
  }
  for(int i = n - 1; i >= 0; i--) printf("%d\n", o[i]);
}