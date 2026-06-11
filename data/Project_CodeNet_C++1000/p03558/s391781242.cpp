#include <cstdio>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
  int k;
  cin >> k;
  while(k % 2 == 0){
    k /= 2;
  }
  while(k % 5 == 0){
    k /= 5;
  }
  vector<int> digitSum_mod(k, 1e9);
  deque<int> dq;
  digitSum_mod[1] = 1;
  dq.push_back(1);
  while(!dq.empty()){
    int u = dq.front(); dq.pop_front();

    if (digitSum_mod[u*10 % k] > digitSum_mod[u]){
      digitSum_mod[u*10 % k] = digitSum_mod[u];
      dq.push_front(u*10 % k);
    }

    if (digitSum_mod[(u+1) % k] > digitSum_mod[u] + 1){
      digitSum_mod[(u+1) % k] = digitSum_mod[u] + 1;
      dq.push_back((u+1) % k);
    }
  }

  cout << digitSum_mod[0] << endl;

  return 0;
}
