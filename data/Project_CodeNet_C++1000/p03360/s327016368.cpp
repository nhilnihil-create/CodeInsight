#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <utility>
using namespace std;

int main(){
  vector<long long> v(3, 0);
  cin >> v[0] >> v[1] >> v[2];
  int k;
  cin >> k;
  sort(v.begin(), v.end());
  v[2] = pow(2, k) * v[2];
  cout << v[0] + v[1] + v[2] << endl;
}