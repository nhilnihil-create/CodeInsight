#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,x;
  cin >> n >> x;
  vector<int> m(n);
  int i;
  int cnt = 0;
  for(i=0;i<n;i++) cin >> m[i];
  sort(m.begin(),m.end());
  for(i=n-1;i>=1;i--) {
    x -= m[i];
    cnt++;
  }
  cnt += x/m[0];
  cout << cnt << "\n";
  return 0;
}