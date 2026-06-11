#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <deque>

using namespace std;
const long long P = 1000000007;

int main() {
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int count = 0;
  int tmp = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == tmp) {
      count++;
      tmp = 0;
    }else {
      tmp = a[i];
    }
  }
  cout << count << endl;
  return 0;
}
