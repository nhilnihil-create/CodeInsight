#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const ll INF = 1e14;
const int MOD = 1000000007;
int n = 503,c = 31;
vector<vector<int>> d(c,vector<int>(c,0));
vector<int> col_0,col_1,col_2;
vector<ll> ch_0(c,0),ch_1(c,0),ch_2(c,0);
 
int main() {
  cin >> n >> c;
  rep(i,c)rep(j,c) cin >> d.at(i).at(j);
  rep(i,n)rep(j,n){
    int a; cin >> a;--a;
    if((i+j)%3 == 0) col_0.push_back(a);
    else if((i+j)%3 == 1) col_1.push_back(a);
    else col_2.push_back(a);
  }
  
  rep(i,c){
    for(auto p:col_0){
      ch_0.at(i) += d.at(p).at(i);
    }
    for(auto p:col_1){
      ch_1.at(i) += d.at(p).at(i);
    }
    for(auto p:col_2){
      ch_2.at(i) += d.at(p).at(i);
    }
  }
  
  ll ans = INF;
  rep(i,c)rep(j,c)rep(k,c){
    if(i==j || j==k || k==i) continue;
    ans = min(ans,ch_0.at(i) + ch_1.at(j) + ch_2.at(k));
  }
  
  cout << ans << endl;    
  
  return 0;
}

