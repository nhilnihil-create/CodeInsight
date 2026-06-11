#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  char last = *str.rbegin();
  set<string> st = {str};
  bool flag = true;
  while (cin >> str) {
    if (last != *str.begin())
      flag = false;
    if (st.find(str) != st.end())
      flag = false;
    st.insert(str);
    last = *str.rbegin();
  }
  cout << (flag ? "Yes" : "No") << endl;
}
