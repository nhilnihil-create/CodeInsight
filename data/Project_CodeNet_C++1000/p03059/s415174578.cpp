#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,t;cin >> a>>b>>t;
  int i=1;
  int cnt=0;
  while(i <= t){
    if (i%a == 0) cnt += b;
    i++;
  }
  cout << cnt << endl;
}
