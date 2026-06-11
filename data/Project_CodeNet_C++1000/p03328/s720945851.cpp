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
  int a, b, t=0,ans;
  cin >> a >> b;
  vector<int> tou(499500, 0);

  rep(i, 999){
    t += i + 1;
    tou[t] = 1;
  }
  bool flag = true;
  for(int i = 1; i < 499500; i++){
    if(tou[i+a]==1 && tou[i+b]==1) {
      ans = i;
      for(int j = i+a+1; j < i+b; j++){
        if (tou[j] == 1) flag = false;
      }
      if(flag) break;
      flag = true;
    }
  }
  print(ans);

}
