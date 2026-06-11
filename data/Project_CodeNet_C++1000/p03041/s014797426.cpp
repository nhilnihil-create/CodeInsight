#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,k; cin >> n >> k;
  string s; cin >> s;
  
  s[k-1] = tolower(s[k-1]);

  cout << s << endl;

  return 0;
}
