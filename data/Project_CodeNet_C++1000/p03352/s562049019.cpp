#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>

//#include <bits/stdc++.h>
using namespace std;
#define print(x) cout<<(x)<<endl
#define prints(x, y) cout<<(x)<<" "<<(y)<<endl
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long int
#define pb push_back

int main() {
  ll N, ans = 1, tmp;
  cin >> N;
  for(int i = 2; i <= sqrt(N); i++){
    int j = 1; tmp = 0;
    while(tmp <= N){
      tmp = pow(i, j);
      if (tmp <= N) ans = max(ans, tmp);
      j++;
    }
  }
  print(ans);

}
