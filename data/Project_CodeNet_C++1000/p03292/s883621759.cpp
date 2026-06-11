#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> num(3);
  cin >>num.at(0) >> num.at(1)>>num.at(2);
  sort(num.begin(), num.end());
  int a = num.at(2)-num.at(1);
  int b = num.at(1)-num.at(0);
    cout << a + b <<endl;
}
