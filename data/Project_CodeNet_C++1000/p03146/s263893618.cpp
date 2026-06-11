// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define rep(i,n) for (int i = 0; i < n; ++i)
#define repr(i,n) for (int i = n; i > 0; --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100;
const int INF = (1<<12);

int main() {
  int s;
  cin >> s;
  map<int,int> A;
  int i = 1;
  A[s] = i;
  while(1){
    if(s%2 == 0) {
      s /= 2;
    }
    else {
      s = 3 * s + 1;
    }
    i++;
    if(A[s]) {
      break;
    }
    else {
      A[s] = i;
    }
  }
  cout << i << endl;
  return 0;
}