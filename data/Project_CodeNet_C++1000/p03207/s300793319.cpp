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

const long INF = (1<<30);
 
int main() {
  int n,p[11];
  cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> p[i];
    sum += p[i];
  }
  
  sort(p,p+n);
  
  cout << sum - p[n-1]/2 << endl;
}