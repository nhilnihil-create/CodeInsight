#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int rating = 0;
  int result = 0;
  double perf = 0;
  cin >> rating >> result;
  perf = result * 2 - rating;
  cout << perf << endl;
}