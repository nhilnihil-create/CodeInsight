#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {

  string s;
  ll k;
  cin >> s >> k;
  for(int i = 0; i < k; i++) {
    if(s.at(i) != '1') {
      cout << s.at(i) << endl;
      return 0;
    }
  }
  cout << '1' << endl;
}