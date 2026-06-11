#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = (1<<30);

int main() {
  int n,a[20000];
  cin >> n;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    while(a[i] % 2 == 0) {
      a[i] /= 2;
      cnt++;
    }
  }
  
  cout << cnt << endl; 
}
