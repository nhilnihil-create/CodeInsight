#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
  long N, M;
  cin >> N >> M;
  
  long A[N], B[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  
  vector<pair<long, long>> stores; //pair<price, count>
  for (int i = 0; i < N; i++) {
    pair<long, long> store = make_pair(A[i], B[i]);
    stores.push_back(store);
  }
  
  sort(stores.begin(), stores.end());
  
  long ans = 0;
  for (auto store : stores){
    ans += store.first * min(store.second, M);
    M -= min(store.second, M);
    if (M == 0) break;
  }
  
  cout << ans << endl;
  
  return 0;
}
