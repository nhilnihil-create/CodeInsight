/*  -*- coding: utf-8 -*-
 *
 * a.cc: A - F
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>

using namespace std;

/* constant */

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  int a, b;
  cin >> a >> b;

  if (a + b == 15) putchar('+');
  else if (a * b == 15) putchar('*');
  else putchar('x');
  putchar('\n');
  
  return 0;
}
