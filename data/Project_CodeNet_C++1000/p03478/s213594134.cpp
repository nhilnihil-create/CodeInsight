#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,a,b; cin >> n >> a >> b;

  int ans = 0;
  
  for(int i = 1;i<=n;i++){
    int tmp = 0;
    string s;
    s = to_string(i);
    rep(j,s.size()){
      int x = s[j]-'0';
      tmp+=x;
    }
    if(a<=tmp && tmp<=b) ans+=i;
  }

  cout << ans << endl;
  
  return 0;
}
