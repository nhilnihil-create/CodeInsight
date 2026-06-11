#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  string S;
  int ans = 10000;
  cin >> S;
  rep(i,S.size()-2){
  string A = S.substr(i,3);
    int n = stoi(A);
    int a = abs(753-n);
    ans = min(ans,a);
  }
  cout << ans;
}