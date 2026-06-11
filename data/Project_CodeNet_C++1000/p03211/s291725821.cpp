#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s;
  cin >> s;
  vector<int> a;
  rep(i,s.size()-2){
    int x = stoi(s.substr(i,3));
    a.push_back(abs(753-x));
  }
  sort(a.begin(),a.end());
  cout << a.at(0) << endl;
 }
