#include <bits/stdc++.h>
using namespace std;

int main() {
  //駐車時間
  int n;
  //料金
  int a,b;
  
  cin >> n >> a >> b;
  
  int fee1 = a * n;
  int fee2 = b;
  
  int ans = min(fee1,fee2);
  
  cout << ans << endl;
}
