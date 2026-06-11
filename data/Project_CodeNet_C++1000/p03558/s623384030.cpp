#include<bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(){
  int k; cin >> k;
  deque< pair<int, int> > pq;
  vector<int> c(k+1, 1e9);
  pq.push_back({0, 1});
  while(!pq.empty()) {
    pair<int, int> p = pq.front();
    c[p.second] = min(c[p.second], p.first);
    pq.pop_front();
    if(c[(p.second+1)%k] == 1e9) pq.push_back({p.first+1, (p.second+1)%k});
    if(c[(p.second*10)%k] == 1e9) pq.push_front({p.first, (p.second*10)%k});
  }
  cout << c[0]+1 << endl;

  return 0;
}

// EOF
