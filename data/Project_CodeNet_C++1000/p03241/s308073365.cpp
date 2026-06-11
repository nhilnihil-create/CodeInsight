#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  ll N, M, ans;
  cin >> N >> M;

  ll a = M/N;

  for(int i = a; i > 0; i--){
    if(M % i == 0) {
      ans = i;
      break;
    }
  }
  print(ans);
}
