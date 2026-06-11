#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  map<int, int> mp;
  for (int i = 0; i < N; i++){
    mp[A[i]]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (auto P : mp){
    pq.push(P);
  }
  for (int i = 0; i < M; i++){
    int B, C;
    cin >> B >> C;
    int total = 0;
    while (1){
      if (pq.empty()){
        break;
      }
      int num = pq.top().first;
      int cnt = pq.top().second;
      if (num >= C){
        break;
      }
      pq.pop();
      if (total + cnt <= B){
        total += cnt;
      } else {
        pq.push(make_pair(num, cnt - (B - total)));
        total = B;
        break;
      }
    }
    pq.push(make_pair(C, total));
  }
  long long ans = 0;
  while (!pq.empty()){
    ans += (long long) pq.top().first * pq.top().second;
    pq.pop();
  }
  cout << ans << endl;
}