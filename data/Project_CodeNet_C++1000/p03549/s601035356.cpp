#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  n -= m;
  int seki = pow(2, m);
  int ans = m*1900*seki + 100*n*seki;
  cout << ans << endl;
}