#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll LIS(vector<int> arr){
  vector<int> dp(arr.size());
  int res = 1;
  dp[0] = 1;

  for(int i = 1;i < arr.size();i++){
    dp[i] = 1;
    for(int j = 0;j < i;j++){
      if(arr[j] < arr[i]){
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    res = max(res, dp[i]);
  }
  return res;
}
ll LDS(vector<int> arr){
  reverse(arr.begin(), arr.end());
  return LIS(arr);
}
int main(){
//  freopen("connect.in", "r", stdin);
//  freopen("connect.out", "w", stdout);
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, a, b;
  cin >> n >> a >> b;
  if(a + b > n + 1 || a == 1 && b != n || b == 1 && a != n){
    cout << -1;
    return 0;
  }
  vector<int> arr(n);
  for(int i = 0;i < arr.size();i++)
    arr[i] = i + 1;
  int ca, cb;
  ca = n, cb = 1;
  reverse(arr.begin(), arr.begin() + b);
  cb = b, ca -= b - 1;
  int cur = b;
  while(ca != a && cur < arr.size()){
    reverse(arr.begin() + cur, arr.begin() + cur + min(n - cur, min(ca - a + 1, b)));
//    swap(arr[cur], arr[cur + 1]);
    int x = min(n - cur, min(ca - a + 1, b));
    ca -= x - 1;
    cur += x;
  }
  if(ca != a){
    cout << -1;
  }else{
//    assert(LIS(arr) == a);
//    assert(LDS(arr) == b);
    for(auto el : arr)
      printf("%d ", el);
  }
}
