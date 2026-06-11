#include <bits/stdc++.h>
using namespace std;
const int mx = 100100100;

int main(){
  int n;
  cin >> n;
  queue<int> que;
  int ans = 0;
  que.push(3);
  que.push(5);
  que.push(7);
  while(que.front() <= n){
    int x = que.front();
    que.pop();
    bool f1 = false, f2 = false, f3 = false;
    int m = x;
    while(m > 0){
      if(m %10 == 3) f1 = true;
      if(m %10 == 5) f2 = true;
      if(m %10 == 7) f3 = true;
      m /= 10;
    }
    if(f1 && f2 && f3) ++ans;
    que.push(x*10 + 3);
    que.push(x*10 + 5);
    que.push(x*10 + 7);
  }
  cout << ans << endl;
}