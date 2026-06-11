#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  if(n % 2 == 0) {
    cout << n << " " << n << " " << n / 2 << endl;
  } else {
    for(int i = 1; i <= 3500; i++) {
      for(int j = i; j <= 3500; j++) {
        if((4 * i * j - n * i - n * j) == 0) {
          continue;
        }
        if((n * i * j) % (4 * i * j - n * i - n * j) == 0) {
          if((4 * i * j - n * i - n * j) > 0) {
            cout << i << " " << j << " ";
            cout << (n * i * j) / (4 * i * j - n * i - n * j) << endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}