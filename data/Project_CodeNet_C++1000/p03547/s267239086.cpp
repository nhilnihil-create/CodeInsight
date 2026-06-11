#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  char x,y; cin >> x >> y;
  if(x<y) cout << "<" << endl;
  else if(x>y) cout << ">" << endl;
  else cout << "=" << endl;
  
  return 0;
}
