#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s; cin >> s;
  int a = 0, b = 0, c = 0;
  FOR(i,0,s.length()) {
    if(s[i] == 'a') a++;
    if(s[i] == 'b') b++;
    if(s[i] == 'c') c++;
  }
  int x = min(a, min(b, c));
  a -= x;
  b -= x;
  c -= x;
  if(a > 1 || b > 1 || c > 1) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}