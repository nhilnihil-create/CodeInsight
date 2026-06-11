#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  bool ans  = false;
  rep(i,26)rep(j,16){
    int sum = 4*i + 7*j;
    if(sum == n){
      ans  = true;
    }
  }
  puts(ans?"Yes":"No");
 }
