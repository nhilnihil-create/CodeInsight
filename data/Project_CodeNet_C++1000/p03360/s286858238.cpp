#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,K;
  cin >> A >> B >> C >> K;
  priority_queue<int> pq;
  pq.push(A);
  pq.push(B);
  pq.push(C);
  for(int i=0;i<K;i++){
    int x=pq.top();
    pq.pop();
    pq.push(x*2);
  }
  int ans=0;
  while(!pq.empty()){
    ans+=pq.top();
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}
