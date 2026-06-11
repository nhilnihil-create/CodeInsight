#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long
#define lli long long int

using namespace std;
using P = pair<int,int>;

int main(){

  int N, a;
  cin >> N;
  int ans = 0;
  vector<int> A1(N);
  vector<int> A2(N);

  for (int i = 0; i < N; i++){
    cin >> a;
    A1.at(i) = a;
  }
  for (int i = 0; i < N; i++){
    cin >> a;
    A2.at(i) = a;
  }

  int x = N-1;

  while (x >= 0) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
      // cout << "i " << i << endl;
      if(i <= x){
        // cout << "i <= x " << A1.at(i) << endl;;
        sum += A1.at(i);
      }
      if (i == x){
        // cout << "i == x " << A2.at(i) <<endl;;
        sum += A2.at(i);
      }
      if (i > x){
        // cout << "i > x " << A2.at(i) <<endl;;
        sum += A2.at(i);
      }
    }
    // cout << "sum "<<sum << endl;
    ans = max(ans, sum);
    x--;
  }

  cout << ans << endl;

  return 0;
}