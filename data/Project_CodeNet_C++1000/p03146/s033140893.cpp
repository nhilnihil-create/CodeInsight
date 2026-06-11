#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int s; cin >> s;
  int max = 1000000;

  vector<int> term;
  term.push_back(s);
  int ans;
  bool flag = false;
  for(int i = 1;i<=max;i++){
    int tmp = term[i-1];
    if(tmp%2==0) tmp = tmp/2;
    else tmp = 3*tmp+1;
    rep(j,term.size()) if(tmp==term[j]){
      ans = i+1;
      flag = true;
    }    
    term.push_back(tmp);
    if(flag) break;
  }

  cout << ans << endl;
  
  return 0;
}
