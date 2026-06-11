#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  vector<int> a(6);
  cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
  vector<int> b(4);
  b[0]=0;
  b[1]=0;
  b[2]=0;
  b[3]=0;
  for (int i=0; i<6; i++) {
    b[a[i]-1]=b[a[i]-1]+1;
  }
  sort(b.begin(),b.end());
  if (b[0]==1 && b[1]==1 && b[2]==2 && b[3]==2) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}