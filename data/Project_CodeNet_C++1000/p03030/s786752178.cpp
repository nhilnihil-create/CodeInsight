#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<pair<string,int>,int>> list(n);
  for(int i=0; i<n; i++) {
    string s;
    int p;
    cin >> s >> p;
    list[i].first.first = s;
    list[i].first.second = p*-1;
    list[i].second = i+1;
  }
  sort(list.begin(),list.end());
  for(int i=0; i<n; i++) {
    cout << list[i].second << endl;
  }
}
