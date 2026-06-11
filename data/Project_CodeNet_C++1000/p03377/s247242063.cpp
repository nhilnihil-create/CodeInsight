#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b,x; cin >> a >> b >> x;
  bool ok = false;

  for(int i = 0;i<=b;i++)
    if(i+a==x) ok = true;

  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}
