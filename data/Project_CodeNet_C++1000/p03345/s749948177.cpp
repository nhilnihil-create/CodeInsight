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

  ll A, B, C, K;
  cin >> A >> B >> C >> K;

  ll BC = B+C;
  ll AC = A+C;
  if(K%2 != 0) cout << (B+C)-(A+C) << endl;
  else cout << -1*((B+C)-(A+C)) << endl;

  return 0;
}