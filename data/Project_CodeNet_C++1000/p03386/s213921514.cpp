#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;

int main(){
  int a,b,k; cin >> a >> b >> k;

  vector<int> ans;

  for(int i = 0; i < k; i++){
    if(a+i > b) break;
    ans.push_back(a+i);
    ans.push_back(b-i);
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()),ans.end());
  for(int v: ans) cout << v << endl;
  return 0;
}
