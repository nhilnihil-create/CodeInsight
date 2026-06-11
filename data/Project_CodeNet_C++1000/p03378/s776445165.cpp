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

int main() {
  int n,m,x;
  cin >> n >> m >> x;
  vector<int> A(n);
  if(x == 0 || n == x){
    cout << 0 << endl; 
    return 0;
  }
  rep(i,n) A[i] = 0;
  rep(i,m){
    int t;
    cin >> t;
    A[t] = 1;
  }
  int cost = 0;
  int ans = 0;
  for(int i = 0; i < x; i++){
    cost += A[i+1];
  }
  ans = cost;
  cost = 0;
  for(int i = n; i > x; i--){
    cost += A[i-1];
  }
  cout << min(ans,cost) << endl;

  return 0;
}