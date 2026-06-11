#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  int s;
  string k;
  cin >> k >> s;

  vector<string> ss;

  for (int i = 0; i < k.size(); i++) {
    string temp;
    for (int j = i; j < k.size(); j++) {
      temp.push_back(k[j]);

      if (temp.size() <= s) ss.push_back(temp);
    }
  }

  auto func = [&](string a, string b) { return a < b; };

  sort(ss.begin(), ss.end(), func);
  ss.erase(unique(ss.begin(), ss.end()), ss.end());

  cout << ss[s - 1] << endl;
}