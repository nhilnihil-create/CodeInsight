#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, thousand, hundred, ten, one;
  cin >> N;
  one = N % 10;
  ten = (N % 100 - one)/10;
  hundred = (N % 1000 - ten - one)/100;
  thousand = (N - hundred - ten - one)/1000;
  if ((thousand == hundred && hundred == ten)||(hundred == ten && ten == one)) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}