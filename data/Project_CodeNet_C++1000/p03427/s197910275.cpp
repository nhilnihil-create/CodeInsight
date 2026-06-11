# include <iostream>
# include <string>
using namespace std;

int main() {
  string n; cin >> n;
  int digit_sum;
  if (n.size() == 1) digit_sum = n[0] - '0';
  else {
    string tmp = "";
    for (int i = 0; i < n.size() - 1; ++i) tmp.append("9");
    if (n.substr(1, n.size() - 1) == tmp) digit_sum = n[0] - '0' + 9 * (n.size() - 1);
    else digit_sum = n[0] - '1' + 9 * (n.size() - 1);
  }
  cout << digit_sum << endl;
  
  return 0;
}