#include<bits/stdc++.h>

using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  
  vector<int> max_sushi(N, 0);
  priority_queue<pair<int, int>> pq;
  for(int i = 0; i < N; i++){
    int t, d;
    cin >> t >> d;
    t--;
    max_sushi[t] = max(d, max_sushi[t]);
    pq.push(make_pair(d, t));
  }
  
  vector<int> a(N, 0);
  long long delicious = 0;
  vector<pair<int, int>> used;
  for(int i = 0; i < K; i++){
    delicious += pq.top().first;
    used.push_back(pq.top());
    a[pq.top().second]++;
    pq.pop();
  }
  sort(used.begin(), used.end());
  
  long long kind = 0;
  priority_queue<int> pq2;
  for(int t = 0; t < N; t++){
    if(a[t] == 0 && max_sushi[t]) pq2.push(max_sushi[t]);
    else if(a[t]) kind++;
  }
  
  long long point = delicious + kind * kind;
  
  for(int i = 0; i < used.size() && !pq2.empty();){
    while(i < used.size() && a[used[i].second] <= 1) i++;
    if(i < used.size()){
      delicious -= used[i].first;
      a[used[i].second]--;
      i++;
      delicious += pq2.top();
      pq2.pop();
      kind++;
      point = max(delicious + kind * kind, point);
    }
  }
  
  cout << point << endl;
  
  return 0;
}