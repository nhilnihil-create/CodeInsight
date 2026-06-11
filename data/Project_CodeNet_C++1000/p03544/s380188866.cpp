#include <bits/stdc++.h>
using namespace std;

int64_t lucas_num(int n, vector<int64_t> &vec) {
  int64_t n1 = 0, n2 = 0;
  if (vec.at(n) != 0) {
    return vec.at(n);
  } else {
    int64_t result = lucas_num(n - 1, vec) + lucas_num(n - 2, vec);;
    vec.at(n) = result;
    return result;
  }
}

int main() {
  int num;
  cin >> num;
  
  vector<int64_t> vec(100);
  vec.at(0) = 2;
  vec.at(1) = 1;
  
  cout << lucas_num(num, vec) << endl;
}