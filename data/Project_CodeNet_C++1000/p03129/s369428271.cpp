#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e9 + 7;

int n, k;

int main() {
  cin >> n >> k;
  if(k > (n + 1)/ 2) {
    cout << "NO";
  }
  else 
    cout << "YES";
}