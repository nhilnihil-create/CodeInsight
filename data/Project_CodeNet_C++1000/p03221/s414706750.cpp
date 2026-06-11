#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

string numstring(int num){
  string s;
  for(int i=0; i<6; ++i){
    s += (char)('0'+ num%10);
    num /= 10;
  }
  reverse(s.begin(),s.end());
  return s;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<P>> city(n+1);
  for(int i=1; i<=m; ++i){
    int pi, yi;
    cin >> pi >> yi;
    city[pi].push_back(make_pair(yi,i));
  }
  vector<string> ans(m+1);
  for(int i=1; i<=n; ++i){
    if(city[i].size() == 0) continue;
    sort(city[i].begin(),city[i].end());
    
    string PFs = numstring(i);
    int citynum = 1;
    for(auto pj: city[i]){
      string Citys = numstring(citynum);
      ++citynum;
      ans[pj.second] = PFs + Citys;
    }
  }
  for(int i=1; i<=m; ++i){
    cout << ans[i] << endl;
  }
}