#include<bits/stdc++.h>
using namespace std;

vector<int64_t> calculated(87, 0);

int64_t lucas_number(int);

int main()
{
  int n;
  cin >> n;
  
  int64_t result = lucas_number(n);
  cout << result << endl;
}

int64_t lucas_number(int n) {
  if (n == 0) {
    return 2;
  }
  if (n == 1) {
    return 1;
  }
  
  if (calculated.at(n) != 0) {
    return calculated.at(n);
  }
  
  return calculated.at(n) = lucas_number(n - 1) + lucas_number(n - 2);
}