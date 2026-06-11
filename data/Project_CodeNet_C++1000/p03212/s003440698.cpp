#include <bits/stdc++.h>
using namespace std;

template <typename T>
string ToString(const T& n) {
  ostringstream stm;
  stm << n;
  return stm.str();
}

string injection(string x, int k, string a) {
  x.insert(k, a);
  return x;
}

void addPtoSet(unordered_set<string>& s, string p, int n) {
  bool three = false, five = false, seven = false;
  for(int i = 0; i < p.size(); i++){
    if(p[i] == '3'){
      three = true;
    } else if(p[i] == '5'){
      five = true;
    } else if(p[i] == '7'){
      seven = true;
    }
  }
  int P = stoi(p);
  if (n >= P && three && five && seven) {
    s.insert(p);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  string N;
  cin >> N;
  int n = stoi(N);
  vector<unordered_set<string>> s(10);
  s[2].insert("35");
  s[2].insert("53");
  int ans = 0;
  for (int i = 3; i <= N.length(); i++) {
    for (auto x : s[i - 1]) {
      for (int j = 0; j <= x.length(); j++) {
        addPtoSet(s[i], injection(x, j, "3"), n);
        addPtoSet(s[i], injection(x, j, "5"), n);
        addPtoSet(s[i], injection(x, j, "7"), n);
      }
    }
    ans += s[i].size();
  }
  cout << ans << endl;
}
