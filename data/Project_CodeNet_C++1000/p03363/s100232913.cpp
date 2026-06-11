#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long A[N];
  for (int i = 0; i < N; i++) cin >> A[i];
  
  long long sum[N];
  map<long long, long long> Map;
  queue<long long> Que;
  bool flag = false;
  Map[0] = 1;
  for (int i = 0; i < N; i++){
    if (i == 0) sum[i] = A[i];
    else sum[i] = sum[i - 1] + A[i];
    Map[sum[i]]++;
    if (Map[sum[i]] == 2) Que.push(sum[i]);
  }
  
  long long count = 0;
  while (!Que.empty()){
    long long a = Que.front();
    Que.pop();
    count += Map[a] * (Map[a] - 1) / 2;
  }
  
  cout << count << endl;
}