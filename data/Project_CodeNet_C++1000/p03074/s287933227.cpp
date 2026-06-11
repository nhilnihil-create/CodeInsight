#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

void solve(){
  int n, k, ans = 0, j = 0; cin >> n >> k;
  string s; cin >> s;
  queue<int> q;
  for(int i = 0; i < n;){
    while(s[i] == '1'){
      i++;
    }
    if(q.size() >= k){
      //cout << j << " ~ " << i << endl;
      ans = max(ans, i - j);
      j = q.front();
      q.pop();
    }
    while(s[i] == '0'){
      i++;
    }
    q.push(i);
  }
  //cout << j << endl;
  ans = max(ans, n - j);
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
