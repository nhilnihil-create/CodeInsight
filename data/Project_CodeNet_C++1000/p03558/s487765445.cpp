#include<bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;

  vector<int> d(K, K);
  deque<pair<int,int>> q;
  q.emplace_back(1, 1);
  while(!q.empty()) {
    auto n=q.front().first;
    auto s=q.front().second;
    q.pop_front();
    if(d[n] <= s) continue;
    d[n] = s;
    q.emplace_front((n*10)%K, s);
    q.emplace_back((n+1)%K, s+1);
  }
  cout << d[0] << endl;
}
