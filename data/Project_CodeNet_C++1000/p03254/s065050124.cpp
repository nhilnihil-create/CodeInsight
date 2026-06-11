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

using namespace std;

int main(){

  int N, x, a;
  cin >> N >> x;
  int ans = 0;
  vector<int> vec(N);

  for (int i = 0; i < N; i++){
    cin >> a;
    vec.at(i) = a;
  }
  sort(vec.begin(), vec.end());

  for (int i = 0; i < N; i++) {
    x -= vec.at(i);
    if(x < 0){
      cout << ans << endl;
      return 0;
    } else if (i != N-1 && x > 0){
      ans++;
    } else if(x == 0){
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}