#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n,m;
  cin >> n >> m;
  
  int food[m] = {0};
  int k,a;
  rep(i,n){
    cin >> k;
    rep(j,k){
      cin >> a;
      food[a-1]++;
    }
  }
  
  int ans = 0;
  rep(i,m){
    if(food[i] == n){
      ans++;
    }
  }
  
  cout << ans << endl;
      
}