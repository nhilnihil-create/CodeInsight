#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"
 
using namespace std;

int comp_two_sum_of_digits (int a, int b) {
  int sum = 0;
  while (a > 0) {
    sum += a % 10;
    a /= 10;
  }
  while (b > 0) {
    sum += b % 10;
    b /= 10;
  }
  return sum;
}

int main() {
  int N; cin >> N;
  
  int ans = 10000000;
  for (int i=1; i<int(N/2)+1; i++) {
    int j = N - i;
    int res = comp_two_sum_of_digits(i, j);
    if (ans > res) ans = res;
  }
  cout << ans << endl;
}