#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> ret;
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      ret.push_back(i);
      if (i * i != m) ret.push_back(m / i);
    }
  }
  sort(ret.begin(), ret.end());
  int ans = 1;
  for(int i=0; i<ret.size(); i++){
    if(m/ret[i]>=n) ans = max(ans, ret[i]);
  }
  cout << ans << endl;
  return 0;
}
