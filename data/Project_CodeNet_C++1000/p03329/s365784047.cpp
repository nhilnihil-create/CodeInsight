#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long


int main(){
  int n;
  cin >> n;
  int ans = 1e9;
  stack<int> vec6, vec9;
  for(int i = 0; i <= n; i++){
    for(int i = 0; i < 9; i++){
      vec6.push(pow(6, i)); vec9.push(pow(9, i));
    }
    int tmp = i;
    int cnt = 0;
    while(tmp){
      int x = vec6.top();
      vec6.pop();
      cnt += tmp / x;
      tmp = tmp % x;
    }
    tmp = n - i;
    while(tmp){
      int x = vec9.top();
      vec9.pop();
      cnt += tmp / x;
      tmp = tmp % x;
    }
    ans = min(ans, cnt);
  }
  cout << ans <<endl;
}
    
