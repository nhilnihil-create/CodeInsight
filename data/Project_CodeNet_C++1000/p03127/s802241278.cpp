#include <bits/stdc++.h>
using namespace std;

bool livesAlone(vector<int> &as) {
  int living = 0;
  for (const int &a : as) {
    if (a > 0) { living++; }
  }
  return (living == 1);
}

void attack(vector<int> &as) {
  int power = 1e9 + 1;
  int index = 1e6;
  for (int i = 0; i < as.size(); i++) {
    if (as[i] < 1) { continue; }
    if (power > as[i]) {
      power = as[i];
      index = i;
    }
  }

  for (int i = 0; i < as.size(); i++) {
    if (i == index) { continue; }
    as[i] %= power;
  }
}

int main(void) {
  int n;
  cin >> n;
  vector<int> as(n);
  for (int &a : as) {
    cin >> a;
  }

  while (!livesAlone(as)) {
    attack(as);
  }
  
  int power = 0;
  for (const int &a : as) {
    power = max(power, a);
  }

  cout << power << endl;
  return 0;
}