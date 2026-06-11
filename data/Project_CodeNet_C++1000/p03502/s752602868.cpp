#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, tmp, sum;
  cin >> N;
  tmp = N;
  sum = 0;
  
  while (tmp >= 10)
  {
    sum += tmp % 10;
    tmp /= 10;
  }
  sum += tmp;
  
  if (N % sum == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}