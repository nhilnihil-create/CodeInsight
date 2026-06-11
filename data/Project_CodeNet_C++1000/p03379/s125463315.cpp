#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> xx(n,0);
  int i;
  for(i=0;i<n;i++) cin >> x[i];
  for(i=0;i<n;i++) xx[i] = x[i];
  sort(x.begin(),x.end());
  int d = x[n/2-1];
  int u = x[n/2];
  for(i=0;i<n;i++){
    if(xx[i]<=d) cout << u << "\n";
    else cout << d << "\n";
  }
  return 0;
}