#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s,t; cin >> s >> t;
  reverse(t.begin(),t.end());

  if(s==t) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}
