#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  vector<int> a(3);
  int i;
  for(i=0;i<3;i++) cin >> a[i];
  sort(a.begin(),a.end());
  int xx = 2*a[2]-a[0]-a[1];
  if(xx%2==1) cout << xx/2+2 << "\n";
  else cout << xx/2 << "\n";
  return 0;
}
