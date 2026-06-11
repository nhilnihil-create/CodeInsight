#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
  int a,b; cin >> a >> b;
  if(a - 1 >= b) cout << 2*a - 1 << endl;
  else if(a == b) cout << a + b << endl;
  else cout << 2 * b - 1 << endl;
  return 0;
}
