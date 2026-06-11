#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+100;
const int INF = 1e9;
int dist[MAXN];

int main(){
  int k;
  cin >> k;
  for(int i = 0; i < k; i++) dist[i] = INF;
  dist[k] = 0;  
  
  deque<int> dq;
  dq.push_front(k);
  while(!dq.empty()){
    int u = dq.front();
    dq.pop_front();
    int nxt0 = u == k ? k : (10 * u) % k;
    int nxt1 = (u + 1) % k;
    if(dist[u] < dist[nxt0]){
      dist[nxt0] = dist[u];
      dq.push_front(nxt0);
    }
    if(dist[u] + 1 < dist[nxt1]){
      dist[nxt1] = dist[u] + 1;
      dq.push_back(nxt1);
    }
  }
  cout<<dist[0]<<endl;
  return 0;
}