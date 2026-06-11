#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int count;
  vector<int> sinamono;
  cin >> count;
  for(int i=0;i<count;i++){
	int now;
    cin >> now;
    sinamono.emplace_back(now);
  }
  sort(sinamono.begin(), sinamono.end());
  int hangaku = sinamono.back() / 2;
  int sum = accumulate(sinamono.begin(), sinamono.end(), 0);
  cout << sum - hangaku;
}