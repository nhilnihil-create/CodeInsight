#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,m,k[40],a[40][40], num = 0;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> k[i];
    for(int j = 0; j < k[i]; j++)
      cin >> a[i][j];
  }

  for(int x = 1; x <= m; x++) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < k[i]; j++) {
        if(a[i][j] == x) sum++;
      }
    }
    if(sum == n) num++;
  }

  cout << num << endl;
}