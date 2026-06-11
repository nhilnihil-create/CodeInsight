#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  
  vector<long long>h(N);
  for (int i = 0; i < N; i++) {
    cin >> h.at(i);
  }

  sort(h.begin(), h.end());
  
  vector<long long>dis(N - K + 1);
  for (int i = 0; i < N - K + 1; i++) {
    dis.at(i) = h.at(i + K - 1) - h.at(i);
  }
  
  sort(dis.begin(), dis.end());
  
  cout << dis.at(0) << endl;
}
  
  