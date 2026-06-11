#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  map<int, int> M;
  
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    M[num]++;
  }
//cout << M.size() << "]" << K << endl;
  int ans;
  if (K >= M.size()) {
    ans = 0;
    cout << ans << endl;
    return 0;
  }
  // M.size > K
  int msize = M.size();
  
  typedef pair<int, int> int_pair;
  struct pair_order {
    bool operator()(int_pair& l, int_pair& r) {
    	return tie(l.second, l.first) > tie(r.second, r.first);
    }
  };
  
  priority_queue<int_pair, vector<int_pair> ,pair_order> pq;
  
  for (int_pair m : M) {
    pq.push(m); 
  }
  
  ans = 0;
  while(M.size() > K) {
//cout << K << "[" << msize << "[" << ans << endl;
    int_pair m = pq.top();
    ans += m.second;
    M.erase(m.first);  
    
    pq.pop(); 
  }
  cout << ans << endl;
  
}