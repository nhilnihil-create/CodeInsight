#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const long long INF = 1LL << 60;
const long long P = 1000000007;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  set<string> st;
  for(int i = 1; i <= k; i++) {
    for(int j = 0; j < s.size(); j++) {
      string t = s.substr(j,i);
      st.insert(t);
    }
  }
  auto itr = st.begin();
  itr = next(itr, k-1);
  cout << *itr << endl;
  return 0;
}