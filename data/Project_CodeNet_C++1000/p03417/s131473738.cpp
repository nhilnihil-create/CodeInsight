#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  ll n,m;
  cin >> n >> m;
  if(n == 1 || m == 1){
    if(n == m){
      cout << 1 << endl;
      return 0;
    }
    cout << n * m - 2 << endl;
    return 0;
  }
  n -= 2; m -= 2;
  cout << n * m << endl;
}