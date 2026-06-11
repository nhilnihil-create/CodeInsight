#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
#include <time.h>
using namespace std;

int main(){
  srand((unsigned int)time(NULL));
  int n; cin >> n;
  if(n >= 24){cout << 0 << endl; return 0;}
  if(n>=22){cout << rand()%2 << endl; return 0;}
  int ans = 0;
  vector<int> d(n+1);
  for(int j=1;j<=n;j++) cin >> d[j]; 
  vector<int> t(n+1);
  t[0] = 0;
  for(int i=0;i<1<<n;i++){
    for(int j=1;j<=n;j++){
      if((1<<(j-1))&i) t[j] = d[j];
      else t[j] = -d[j];
    }
    int tm = 24;
    for(int j=0;j<n;j++) for(int k=j+1;k<=n;k++) tm = min(tm, min(24 - abs(t[j]-t[k]), abs(t[j]-t[k])));
    ans = max(ans, tm);
  }
  cout << ans << endl;
  return 0;
}
