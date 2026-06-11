#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
  int n,i,d[55],ans=1e9;
  vector<int> t;
  cin >> n;
  for (i=0;i<n;i++) cin >> d[i];
  sort(d,d+n);
  t.push_back(0);
  for (i=0;i<n;i++){
    if (i%2) t.push_back(d[i]);
    else t.push_back(-d[i]);
  }
  if ((n-1)%2) t.push_back(d[n-1]-24);
  else t.push_back(24-d[n-1]);
  sort(t.begin(),t.end());
  for (i=0;i<n+1;i++) if (ans > t[i+1]-t[i]) ans=t[i+1]-t[i];
  cout << ans << endl;
  return 0;
}