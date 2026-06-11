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
  int N, Y, x=-1, y=-1, z=-1;
  cin >> N >> Y;
  bool finished=false;
  for (int i=0; i<=Y/10000; i++) {
    for (int j=0; j<=Y/5000; j++) {
      if (9000*i+4000*j+1000*N==Y && N-i-j>=0) {
        x=i;
        y=j;
        z=N-i-j;
        finished=true;
        break;
      }
    }
    if (finished) {
      break;
    }
  }
  cout << x << " " << y << " " << z << endl;
}