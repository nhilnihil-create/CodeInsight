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
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, X[1000], Y[1000], S[1000];
  cin >> N;
  FOR(i,0,N) {
    cin >> X[i] >> Y[i];
    S[i] = X[i] + Y[i];
    if((S[i] - S[0]) % 2 != 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  vector<int> values;
  for(int i=30;i>=0;i--) values.push_back(1<<i);
  if(S[0] % 2 == 0) values.push_back(1);
  int M = values.size();
  cout << M << endl;
  FOR(i,0,M) cout << values[i] << " \n"[i==M-1];
  FOR(i,0,N) {
    int xpy = X[i] + Y[i], xmy = X[i] - Y[i];
    for(auto& v : values) {
      if(xpy >= 0) {
        if(xmy >= 0) {
          cout << "R";
          xpy -= v;
          xmy -= v;
        } else {
          cout << "U";
          xpy -= v;
          xmy += v;
        }
      } else {
        if(xmy >= 0){
          cout << "D";
          xpy += v;
          xmy -= v;
        }else{
          cout << "L";
          xpy += v;
          xmy += v;
        }
      }
    }
    cout << endl;
  }
}
