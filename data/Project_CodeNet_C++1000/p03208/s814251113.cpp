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
  int n,k,h[110000];
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> h[i];
  
  sort(h,h+n);
  int mi = 1000000000;
  for(int i = 0; i < n-k+1; i++) {
    mi = min(mi, h[k+i-1] - h[i]);
  }

  cout << mi << endl; 
}