#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  using tsii = tuple<string, int, int>;
  vector<tsii> p(n);
  for (int i=0; i<n; i++) {
    string city;
    int point;
    cin >> city >> point;
    p[i] = make_tuple(city, -point, i+1);
  }
  
  sort(p.begin(), p.end());
  
  for (int i=0; i<n; i++) cout << get<2>(p[i]) << endl;
  
}
