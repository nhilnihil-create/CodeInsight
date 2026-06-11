#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long n,m;
  cin >> n >> m;
  if(n==1&&m==1) cout << 1 << endl;
  else if(2<n&&2<m) cout << (n-2)*(m-2) << endl;
  else if(n==1||m==1) cout << max(n,m)-2 << endl;
  else cout << 0 << endl;
}