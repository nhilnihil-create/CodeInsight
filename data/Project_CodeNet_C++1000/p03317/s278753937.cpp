#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
  double n,k;
  cin >> n >> k;
  vector<int> a(n);
  int i;
  for(i=0;i<n;i++) cin >> a[i];
  if(n<=k) cout << 1 << "\n";
  else if(k==2) cout << n-1 << "\n";
  else cout << ceil((n-1)/(k-1)) << "\n";
  return 0;
}
