#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  long n,m;
  cin >> n >> m;
  if(1<min(n,m)) cout << (n-2)*(m-2) << endl;
  else if(n!=m) cout << max(n,m)-2 << endl;
  else cout << 1 << endl;
}