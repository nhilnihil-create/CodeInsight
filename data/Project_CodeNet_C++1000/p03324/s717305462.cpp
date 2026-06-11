#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef vector<int> vec1;
typedef vector<string> vec2;
typedef vector<double> vec3;

int main() {
  
  int d, n;
  cin >> d >> n;
  int x = 0;
  if(d == 0) {
    if(n == 100) n++;
    cout << n << endl;
    return 0;
  }
  if(d == 1) {
    if(n == 100) x = 100;
    cout << n*100+x << endl;
    return 0;
  }
  if(d == 2) {
    if(n == 100) x = 10000;
    cout << n*10000+x << endl;
    return 0;
  }
}