#include<iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
  int N, M;
  priority_queue<unsigned long long, vector<unsigned long long>, greater<unsigned long long> > A;
  priority_queue<pair<unsigned long long, int> > CB; 
  cin >> N >> M;
  for (int i = 0; i < N; i++){
    unsigned long long tmp;
    cin >> tmp;
    A.push(tmp);
  }

  for (int i = 0; i < M; i++){
    pair<unsigned long long, int> tmp;
    cin >> tmp.second >> tmp.first;
    CB.push(tmp);
  }

  while (!CB.empty()) {
    pair<unsigned long long, int> tmp = CB.top();
    if(A.top() >= tmp.first) break;
    for (int i = 0; i < tmp.second; i++){
      if (A.top() >= tmp.first) break;
      A.pop();
      A.push(tmp.first);
    }
    CB.pop();
  }
  
  unsigned long long ans = 0;
  while (!A.empty()) {
    ans += A.top();
    A.pop();
  }
  printf("%llu\n", ans);
  
}
