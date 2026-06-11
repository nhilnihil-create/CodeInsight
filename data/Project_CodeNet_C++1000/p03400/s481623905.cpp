// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,n) for (int i = 0; i < n; ++i)
#define repr(i,n) for (int i = n; i > 0; --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100;
const int INF = (1<<12);

int func(int a, int d){
  int k = 1;
  while ((k * a + 1) <= d){
    k++;
  }
  return k; 
}

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  int ans = X;
  rep(i,N){
    int a;
    cin >> a;
    ans += func(a,D);
  }
  cout << ans << endl;

  return 0;
}