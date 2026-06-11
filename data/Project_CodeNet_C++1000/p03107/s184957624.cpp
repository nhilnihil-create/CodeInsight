#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){
  string s;
  cin >> s;

  int first_size = s.size();

  sort(s.begin(), s.end());

  auto itr = s.find("1");
  auto itr0 = s.find("0");
  string s0, s1;
  if(itr == string::npos || itr0 == string::npos || s.size() == 1) {
    cout << 0 << endl;
    return 0;
  }

  s0 = s.substr(0, itr);
  s1 = s.substr(itr, s.size()-1);

  auto after_size = max(s0.size(), s1.size()) - min(s0.size(), s1.size());
  cout << first_size - after_size << endl;

  return 0;
}
