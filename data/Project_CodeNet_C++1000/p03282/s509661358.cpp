#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  ll k; cin >> k;

  rep(i,s.size()){
    if((ll)i==k-1){
      cout << s[i] << endl;
      return 0;
    }
    if(s[i]!='1'){
      cout << s[i] << endl;
      return 0;
    }
  }

  cout << s[0] << endl;
  
  return 0;
}
