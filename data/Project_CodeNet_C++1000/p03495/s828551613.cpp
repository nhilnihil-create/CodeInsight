#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  int i;
  for(i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  vector<int> b(200001,0);
  for(i=0;i<n;i++) b[a[i]]++;
  sort(b.begin(),b.end());
  long long cnt = 0;
  for(i=1;i<=k;i++) cnt += b[200001-i];
  cout << n-cnt << "\n";
  return 0;
}
