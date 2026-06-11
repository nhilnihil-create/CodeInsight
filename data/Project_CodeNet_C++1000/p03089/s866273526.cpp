#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> bn(n);
  for(int i=0; i<n; ++i) cin >> bn[i];
  vector<int> ans;
  for(int i=0; i<n; ++i){
    int j = bn.size()-1;
    for( ; j>=0; --j){
      if(bn[j] > j+1){
        cout << -1 << endl;
        return 0;
      }
      if(bn[j] == j+1){
        ans.push_back(j+1);
        break;
      }
    }
    for( ; j<(int)bn.size()-1; ++j){
      bn[j] = bn[j+1];
    }
    bn.pop_back();
  }
  for(int i=n-1; i>=0; --i){
    cout << ans[i] << endl;
  }
}