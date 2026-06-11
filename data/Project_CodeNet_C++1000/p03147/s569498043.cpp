#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int arraymax(int num[], int x, int y) {
  int ma = 0;
  for(int i = x; i <= y; i++) {
    ma = max(ma, num[i]);
  }
  return ma;
}

int main() {
  int n,h[200];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> h[i];
  
  int sum = h[0];
  for(int i = 1; i < n; i++) {
    if(h[i] > h[i-1])
			sum += h[i] - h[i-1];
  }
  
  cout << sum << endl;
}
