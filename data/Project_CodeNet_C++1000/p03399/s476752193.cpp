#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  
  int train = a<b?a:b;
  int bus = c<d?c:d;
  cout << train + bus << endl;
}