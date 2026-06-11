#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  
  vector<int>A(N);
  vector<int>B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i) >> B.at(i);
  }
  
  vector<pair<long long,long long>>p(N);
  for (int i = 0; i < N; i++) {
    p.at(i).first = A.at(i);
    p.at(i).second = B.at(i);
  }
  sort(p.begin(), p.end());
  
  int count = 0;
  long long cost = 0;
  for (int i = 0; i < N; i++) {
    if (count + p.at(i).second <= M){
      cost += p.at(i).first * p.at(i).second;
      count += p.at(i).second;
    }
    else {
      cost += p.at(i).first * (M-count);
      count += M-count;
    }
    if (count == M){
      cout << cost << endl;
      return 0;
    }
  }
}