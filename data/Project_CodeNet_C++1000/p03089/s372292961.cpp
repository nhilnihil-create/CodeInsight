#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>b(n);
  rep(i,0,n){
    cin >> b[i];
    b[i]--;
    if(b[i] > i){
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int>ans;
  while(b.size() > 0){
    for(int i = b.size()-1;i >= 0;i--){
      if(b[i] == i){
        ans.push_back(b[i]);
        b.erase(b.begin()+i);
        break;
      }
    }
  }
  for(int i = ans.size()-1;i >= 0;i--) cout << ans[i]+1 << endl;
}