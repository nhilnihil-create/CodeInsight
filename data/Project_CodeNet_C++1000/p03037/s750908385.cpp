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
  for(int i = 0; i < m; i++)
    cin >> L[i] >> R[i];

  int LL[110000],RR[110000];
  LL[0] = L[0], RR[0] = R[0];
  LL[1] = L[1]; RR[1] = R[1];
  for(int i = 0; i < m-1; i++) {
    if(L[i+1] > LL[i]) LL[i+1] = L[i+1];
    else LL[i+1] = LL[i];
    if(R[i+1] < RR[i]) RR[i+1] = R[i+1];
    else RR[i+1] = RR[i];
  }
  if(LL[m-1] <= RR[m-1])
    cout << RR[m-1] - LL[m-1] + 1 << endl;
  else 
    cout << 0 << endl;
}