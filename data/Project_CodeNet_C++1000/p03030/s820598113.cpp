#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
  fastIO;
  int n;
  cin >> n;

  vector<pair<string, int>> city;
  set<string> st;
  rep(i, n) {
    string s;
    cin >> s;
    int p;
    cin >> p;
    city.push_back(make_pair(s, p));
    st.insert(s);
  }

  vector<string> name;
  for(auto s: st)
    name.push_back(s);
  sort(name.begin(), name.end());

  for(auto n: name) {
    vector<pair<int, int>> scores;
    for(size_t i=0; i<city.size(); ++i) {
      if(n == city.at(i).first) {
        scores.push_back(make_pair(city.at(i).second, i + 1));
      }
    }

    sort(scores.begin(), scores.end());
    for(int i=scores.size()-1; i>=0; --i) {
      // cout << scores.at(i).first << " "  << scores.at(i).second << endl;
      cout << scores.at(i).second << endl;
    }
    scores.clear();
  }
}
