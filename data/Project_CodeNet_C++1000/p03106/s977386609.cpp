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

  int A, B, K;
  cin >> A >> B >> K;
  int ans = 0;

  int mx = max(A,B);

  int cnt = K;
  for (int i = mx; i >= 1; i--) {
    if(A%i == 0 && B%i == 0){
      cnt--;
      if(cnt == 0){
        ans = i;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}