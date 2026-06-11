#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); ++i)
#define rep1(i,n) for (int i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;
const double e = 0.000000001;
string assembleId(int k, int seq){
  string id = to_string(k);
  while(id.size()<6){
    string z = "0";
    id =z.append(id,0,id.size());
  }
  string matsu = to_string(seq);
  while(matsu.size()<6){
    string z = "0";
    matsu =z.append(matsu,0,matsu.size());
  }
  return id.append(matsu,0,matsu.size());
}
int main(){
  int n,m; cin >> n >> m;
  vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> v(n+1);
  rep(i,m){
    int p,y;
    cin >> p >> y;
    pair<int,int> u = make_pair(y,i);
    v[p].push(u);
  }
  vector<string> ans(m);
  rep1(i,n){
    auto q = v[i];
    int cnt=0;
    while(!q.empty()){
      cnt++;
      auto p = q.top();q.pop();
      int t = p.second;
      ans[t]=assembleId(i,cnt);
    }
  }
  for(auto e:ans){
    cout << e << endl;
  }
  return 0;
}