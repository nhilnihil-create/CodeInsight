#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

string make_string(int p, int x){
  string left, right, a, b;
  a=to_string(p); b=to_string(x);
  rep(i,6-a.size()) left+='0';
  left+=a;
  rep(i,6-b.size()) right+='0';
  right+=b;
  return left+right;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<string> ans(m);
  vector<vector<P>> info(n+1);
  rep(i,m){
    int p, y;
    cin >> p >> y;
    p--;
    info[p].push_back(make_pair(y,i));
  }
  rep(i,n){
    if(info[i].size()==0) continue;
    sort(info[i].begin(),info[i].end());
    int tmp=0;
    for(auto x : info[i]){
      tmp++;
      string now = make_string(i+1,tmp);
      ans[x.second]=now;
    }
  }
  //answer
  rep(i,m){
    cout<<ans[i]<<endl;
  }
}