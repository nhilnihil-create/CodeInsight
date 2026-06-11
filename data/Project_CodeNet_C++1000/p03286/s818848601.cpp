#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
int main() {
  int n, count = 1;
  vector<int> array;
  cin >> n;
  if (n==0) {
    cout << 0 << endl;
    return 0;
  }
  while (n!=0) {
    if (n%2==0) {
      array.push_back(0);
    } else {
      array.push_back(1);
      if (count%2==0) {
        n++;
      } else {
        n--;
      }
    }
    // cout << array[count] << ' ' << count << ' ' << n << endl;
    count++;
    n/=2;
  }
  for (int i = array.size()-1; i >= 0; i--) {
    if (array[i]==0) cout << 0;
    else cout << 1;
  }
  cout << endl;
}