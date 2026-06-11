#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<string> w(n); rep(i,n) cin >> w[i];

  bool ok = true;
  rep(i,n){
    for(int j = i+1;j<n;j++) if(w[i]==w[j]) ok = false;
  }

  for(int i = 1;i<n;i++){
    if(w[i-1][w[i-1].size()-1]!=w[i][0]){
      ok = false;
    }
  }
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
