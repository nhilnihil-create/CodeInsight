#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int s, h, r, t, o;
  cin >> s;
  h=(s-(s%100))/100;
  r=s-100*h;
  t=(r-(r%10))/10;
  o=r-10*t;
  cout << h+t+o << endl;
}
