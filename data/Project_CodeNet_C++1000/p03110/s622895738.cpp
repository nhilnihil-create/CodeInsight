#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  double a, ans=0;
  cin >> N;
  string str;
  vector<double> item(N);

  cout << fixed;
  
  for (int i = 0; i < N; i++) {
    cin >> a >> str;
    if (str == "JPY") item.at(i) = a;
    else item.at(i) = a * 380000;
  }
  
  sort(item.begin(), item.end());
  for (int j = 0; j < N; j++) ans = ans + item.at(j);

  cout << ans << endl;
}