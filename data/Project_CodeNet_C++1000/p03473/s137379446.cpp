#include <bits/stdc++.h>
using namespace std;

int main() {
  int rest_hours = 24;
  int current = 0;
  cin >> current;
  rest_hours += 24 - current;
  cout << rest_hours << endl;
}
