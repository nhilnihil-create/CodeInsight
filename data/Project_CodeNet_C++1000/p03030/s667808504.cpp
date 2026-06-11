#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<pair<string, int>, int>> data(n);

  for (int i = 0; i < n; i++) {
      string s;
      int k;
      cin >> s >> k;
      k *= -1;
      data.at(i) = make_pair(make_pair(s,k),i+1);
  }

  sort(data.begin(),data.end());

  for (int i = 0; i < n; i++) {
      cout << data.at(i).second << endl;
  }
}
