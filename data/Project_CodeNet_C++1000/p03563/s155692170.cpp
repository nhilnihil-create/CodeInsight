#include <bits/stdc++.h>
using namespace std;

int main() {
  double now_rate, get_rate, next_rate;
  cin >> now_rate >> next_rate;
  get_rate = (next_rate * 2.0) - now_rate;
  cout << get_rate << endl;
}