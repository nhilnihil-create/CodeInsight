/*  -*- coding: utf-8 -*-
 *
 * b.cc: B: Palindrome-phobia
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

int cns[3];

/* subroutines */

/* main */

int main() {
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) cns[s[i] - 'a']++;
  //for (int i = 0; i < 3; i++) printf("%d ", cns[i]); putchar('\n');

  int minc = cns[0], maxc = cns[0];
  for (int i = 1; i < 3; i++) {
    if (minc > cns[i]) minc = cns[i];
    if (maxc < cns[i]) maxc = cns[i];
  }

  if (maxc <= minc + 1) puts("YES");
  else puts("NO");
  return 0;
}
