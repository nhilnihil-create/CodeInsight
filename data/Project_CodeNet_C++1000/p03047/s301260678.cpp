#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,k;
  cin >>n >>k;
  int cnt = 0;
  rep(i,n-(k-1)) cnt++;
  cout << cnt << endl;
  return 0;
}