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
  
  int sum = 0;
  for(int i = 0; i <= 100; i++) {
    for(int j = 0; j < n; j++) {
      if(h[j] == 0) continue;
      while (h[j] > 0) {
				h[j]--; j++;
			}
			sum++;
    }
  }
  
  cout << sum << endl;
}
