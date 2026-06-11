#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int ans;
  for(int i = 1; i*i <= n; i++)
    ans = i*i;
  
  cout << ans << endl;
}