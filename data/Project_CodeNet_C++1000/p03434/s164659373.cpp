#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  priority_queue <int> queue;
  vector <int> list;
  for(int i = 0; i < N; i++){
    int list_single;
    cin >> list_single;
    queue.push(list_single);
  }

  int sum_a = 0;
  int sum_b = 0;
  while(true){
    sum_a = sum_a + queue.top();
    queue.pop();
    if(queue.size() == 0){
       break;
    }
    sum_b = sum_b + queue.top();
    queue.pop();
    if(queue.size() == 0){
      break;
    }else{
      continue;
    }
  }
  cout << sum_a-sum_b << endl;
}
