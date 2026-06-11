#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef pair<long long, long long> P;
int main(){
  int N, M;
  cin >> N >> M;
  vector<long long> A(N);
  long long ans = 0;
  priority_queue<long long, vector<long long>, greater<long long>> q;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    q.push(A[i]);
  }
  vector<P> B(M);
  for(int i = 0; i < M; i++){
    long long a, b;
    cin >> a >> b;
    B[i] = P(b, a);
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  long long sum = 0;
  for(int i = 0; i < M; i++){
    long long t = B[i].second;
    while(!q.empty() && t > 0){
      if(q.top() < B[i].first){
      	sum += B[i].first;
      	t--;
        q.pop();
      }
      else break;
    }
  }
  while(!q.empty()){
    sum += q.top();
    q.pop();
  }
  cout << sum << endl;
}