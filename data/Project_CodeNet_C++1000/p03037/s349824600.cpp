#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;
const long INF = 2000000000;

int main() {
  int n,m,L[110000],R[110000];
  cin >> n >> m;
  int LL = 1;
  int RR = n;
  for(int i = 0; i < m; i++) {
    cin >> L[i] >> R[i];
    LL = max(LL,L[i]);
    RR = min(RR, R[i]);
  }
  
  int cnt = 0;
  for(int i = 1; i <= n; i++)
    if(i >= LL & i <= RR) cnt++;
  
  cout << cnt << endl;
}