// g++ -std=c++14

//Difficulty according to solve count during contest:
//A B C D H F E I G K L M N P S O Q R J U Z Y X T V W

#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int n;
vector<int> a;
vector<vector<int> > dp;

int func(int l, int r){
  if(dp[l][r] != -1)
    return dp[l][r];
  if(l == r)
    return 0;
  dp[l][r] = 1e18;
  int tot = 0;
  for(int i = l; i <= r; i++)
    tot += a[i];
  for(int i = l; i < r; i++){
      dp[l][r] = min(dp[l][r], func(l, i) + func(i + 1, r) + tot);
  }
  return dp[l][r];
}

int32_t main(){
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  dp.resize(n, vector<int> (n, -1));
  int ans = func(0, n - 1);
  cout << ans << endl;
}
