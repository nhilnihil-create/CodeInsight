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
  int a, b, c, x, ans = 0;
  cin >> a >> b >> c >> x;

  rep(i, a+1){
    rep(j, b+1){
      rep(k, c+1){
        if(500*i + 100*j + 50*k == x) {
          ans++;
          // printf("%d %d %d\n", i, j, k);
        }
      }
    }
  }
  print(ans);

}
