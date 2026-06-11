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
  int n,T;
  pair<int,int> c[110];
  cin >> n >> T;
  for(int i = 0; i < n; i++) 
    cin >> c[i].first >> c[i].second;
  
  sort(c,c+n);

  for(int i = 0; i < n; i++) {
    if(c[i].second <= T) {
      cout << c[i].first << endl;
      return 0;
    }
  } 
  cout << "TLE" << endl;
}