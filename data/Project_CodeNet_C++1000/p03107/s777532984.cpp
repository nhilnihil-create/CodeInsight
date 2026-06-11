#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  int n0=0,n1=0;

  for(int i = 0;i<s.size();i++){
    if(s[i]=='0') n0++;
    if(s[i]=='1') n1++;
  }  

  int ans = 2*min(n0,n1);

  cout << ans << endl;
  
  return 0;
}
