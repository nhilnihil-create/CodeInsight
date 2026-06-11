#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

vector<vector<int>> g;
vector<int> ans;

int main(){
  int m,k; cin >> m >> k;
  int ul = pow(2, m);
  if(ul <= k) cout << -1 << endl;
  else if(m == 0){
    if(k == 0) cout << "0 0" << endl;
    else cout << -1 << endl;
  }else if(m == 1){
    if(k == 0) cout << "0 0 1 1" << endl;
    else cout << -1 << endl;
  }else{
    vector<int> arr;
    for(int i = 0; i < ul; i++){
      if(i == k) continue;
      cout << i << " ";
      arr.push_back(i);
    }
    reverse(arr.begin(), arr.end());
    cout << k;
    for(int v: arr){
      cout << " " << v;
    }
    cout << " " << k << endl;
  }
  return 0;
}
