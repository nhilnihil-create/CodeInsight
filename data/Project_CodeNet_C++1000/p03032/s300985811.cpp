#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, s, n) for(int i = s; i < n; i++)
using namespace std;
using P = pair<int, int>;

int main(){
  int n, k;
  cin >> n >> k;
  int m = min(n, k);
  deque<int> deq;
  rep(i, n){
    int v;
    cin >> v;
    deq.push_back(v);
  }
  int ans = 0;
  rep(i, m+1)rep(j, i+1){
    deque<int> dq(deq);
    priority_queue<int, vector<int>, greater<int>> que;
    rep(a, j){
      int x = dq.front();
      dq.pop_front();
      que.push(x);
    }
    rep(b, i-j){
      int x = dq.back();
      dq.pop_back();
      que.push(x);
    }
    rep(c, k-i){
      if (que.empty()) break;
      if (que.top() < 0) que.pop();
    }
    int sum = 0;
    while(!que.empty()){
      sum += que.top();
      que.pop();
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  
  return 0;
}