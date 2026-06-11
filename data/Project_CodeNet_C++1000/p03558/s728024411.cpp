#include<iostream>
#include<deque>
using namespace std;

int K;
int cost[100001];

int main(){
  cin >> K;

  for(int i = 0; i <= 100000; i++){
    cost[i] = 200000;
  }

  deque<int> deq;
  cost[1] = 1;
  deq.push_back(1);

  while(deq.front() != 0){
    int now = deq.front(); deq.pop_front();
    if(cost[(now * 10) % K] > cost[now]){
      deq.push_front((now * 10) % K);
      cost[(now * 10) % K] = cost[now];
    }
    if(cost[(now + 1) % K] > cost[now] + 1){
      deq.push_back((now + 1) % K);
      cost[(now + 1) % K] = cost[now] + 1;
    }
  }
  cout << cost[0] << endl;
}
