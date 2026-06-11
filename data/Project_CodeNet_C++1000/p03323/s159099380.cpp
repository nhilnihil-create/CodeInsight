#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;

  bool ok = true;
  if(a>8 || b>8) ok = false;
  
  if(ok) cout << "Yay!" << endl;
  else cout << ":(" << endl;
    
  return 0;
}
