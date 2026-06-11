#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n;
  double x[40],sum = 0;
  string u[40];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> x[i] >> u[i];

  for(int i = 0; i < n; i++) {
    if(u[i] == "JPY") sum += x[i];
    else sum += (380000.0 * x[i]);
  }

  cout << sum << endl;
}