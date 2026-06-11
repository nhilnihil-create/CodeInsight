#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>b(n);
  vector<int>ans;
  rep(i,0,n){
    cin >> b[i];
    b[i]--;
  }
  rep(i,0,n){
    rep(j,0,b.size()){
      if(b[b.size()-1-j] == b.size()-1-j){
        ans.push_back(b.size()-1-j);
        b.erase(b.begin()+b.size()-1-j);
        break;
      }
      if(j == b.size()-1){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  rep(i,0,n) cout << ans[n-i-1]+1 << endl;
 }