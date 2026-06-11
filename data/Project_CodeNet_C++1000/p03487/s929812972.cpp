#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int i;
  long long cnt = 0;
  for(i=0;i<n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  for(i=0;i<n;i++){
    if(a[i]>100000){                                                                      cnt++;
      a[i]=0;
    }
  }
  vector<int> b(100001,0);
  for(i=0;i<n;i++) b[a[i]]++;
  for(i=1;i<=100000;i++){
    if(b[i]>i) cnt += b[i]-i;
    else if(b[i]<i) cnt += b[i];
  }
  cout << cnt << "\n";
  return 0;
}
