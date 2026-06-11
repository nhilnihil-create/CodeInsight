#include <iostream>
#include <deque>
#include <utility>
using namespace std;
typedef pair<int, int> vertex; //pair<頂点番号, 距離>

long long int solve(long long int k);
int main(){
  int k; cin >> k;
  cout << solve(k) << endl;

  return 0;
}

long long int solve(long long int k){
  bool visited[k];
  for(int i=0; i<k; i++) visited[i]=false;

  deque<vertex> dq;  dq.push_front(vertex(1, 1));
  visited[1]=true;

  long long int ans;
  while(!dq.empty()){
    //dequeueの先頭をポップし、それが頂点0なら終了
    vertex now = dq.front(); dq.pop_front();
    int cur = now.first, cnt = now.second;
    if(cur==0) return cnt;

    visited[cur]=true;

    //0方向の遷移
    int next= (cur*10)%k;
    if(!visited[next]){
      dq.push_front(vertex(next, cnt));
    }

    //1方向の遷移
    next = (cur+1)%k;
    if(!visited[next]){
      dq.push_back(vertex(next, cnt+1));
    }
  }
}
