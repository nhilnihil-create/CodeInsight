#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i;
  vector<int> a(n);
  for(i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  cout << a[n-1]-a[0] << "\n";
  return 0;
}