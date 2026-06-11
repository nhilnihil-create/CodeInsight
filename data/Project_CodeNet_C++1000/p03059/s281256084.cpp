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
  int a,b,t; cin >> a >> b >> t;
  int s = t / a;
  int ans = s * b;
  cout << ans << endl;
  return 0;
}
