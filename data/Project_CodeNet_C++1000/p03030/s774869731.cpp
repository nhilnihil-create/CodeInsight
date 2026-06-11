#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  map<pair<string, int>, int> m;
  vector<pair<string, int>> list;
  int n;
  cin >> n;

  rep(i,n) {
    string s;
    int num;
    cin >> s >> num;
    list.push_back(make_pair(s, num));
    m.insert(make_pair(make_pair(s, num), i+1));
  }

  sort(list.begin(), list.end());

  list.push_back(make_pair("", INF)); // 番兵

  string before = "";
  vector<int> tmp;
  for (auto x : list) {
    if  (before == x.first) {
      tmp.push_back(x.second);
    } else {
      if (tmp.size() != 0) {
        reverse(tmp.begin(), tmp.end());
        for (auto y : tmp) {
          cout << m.at(make_pair(before, y)) << endl;
        }
        tmp.clear();
      }
      tmp.push_back(x.second);
      before = x.first;
    }
  }
}
