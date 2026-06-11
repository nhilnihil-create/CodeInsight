#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  priority_queue<long long> pq[8]; //ppp, ppm, pmp, mpp, pmm, mpm, mmp, mmm
  for(int i = 0; i < n; i++){
    long long x, y, z;
    cin >> x >> y >> z;
    pq[0].push(x+y+z);
    pq[1].push(x+y-z);
    pq[2].push(x-y+z);
    pq[3].push(-x+y+z);
    pq[4].push(x-y-z);
    pq[5].push(-x-y+z);
    pq[6].push(-x+y-z);
    pq[7].push(-x-y-z);
  }
  long long ans = -1e13;
  for(int i = 0; i < 8; i++){
    long long tmp = 0;
    for(int j = 0; j < m; j++){
      tmp += pq[i].top();
      pq[i].pop();
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
      
    
    