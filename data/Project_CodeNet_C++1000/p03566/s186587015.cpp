//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){

  int N; cin >> N;

  vector <double> T(N + 2), V(N + 2);
  int sum = 0;
  for (int i = 1; i < N + 1; i++){
    double t; cin >> t; sum += t;
    T[i] = T[i - 1] + t;
  }
  T[N + 1] = T[N];
  
  for (int i = 1; i < N + 1; i++){
    cin >> V[i];
  }

  vector <double> ans(sum * 2 + 1);
  for (int i = 0; i < sum * 2 + 1; i++){
    ans[i] = min(0.5 * i, sum - 0.5 * i);
  }

  for (int i = 0; i < sum * 2 + 1; i++){
    double now = 0.5 * i;
    for (int j = 1; j < N + 2; j++){
      if (T[j] < now){
        ans[i] = min(ans[i], V[j] + abs(now - T[j]));
      }else if (T[j - 1] <= now && now <= T[j]){
        ans[i] = min(ans[i], V[j]);
      }else{
        ans[i] = min(ans[i], V[j] + abs(now - T[j]));
      }
    }
  }


  for (int i = sum * 2 - 1; i >= 0; i--){
    if (abs(ans[i] - ans[i + 1]) > 0.5){
      if (ans[i] > ans[i + 1]) ans[i] = ans[i + 1] + 0.5;
      else ans[i] = ans[i + 1] - 0.5;
    }
  }

  double A = 0;

  for (int i = 0; i < sum * 2; i++){
    A += 0.25 * (ans[i] + ans[i + 1]);
  }
  
  cout <<setprecision(32) <<  A << endl;
  


  return 0;
}