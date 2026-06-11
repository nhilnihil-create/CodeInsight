#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b,c,d; cin >> a >> b >> c >> d;
  bool ok = false;

  if(abs(a-c)<=d) ok = true;
  else if(abs(a-b)<=d && abs(b-c)<=d) ok = true;

  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
