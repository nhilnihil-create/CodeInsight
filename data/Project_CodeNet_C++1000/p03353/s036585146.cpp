#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  string s;
  cin >> s;
  int k;
  cin >> k;
  vector<string> res(30000);
  int iter = 0, alpha = 0;
  rep(i,5){
    rep(j,int(s.size())-i){
      rep(k,i+1)res[iter].push_back(s[j+k]);
      iter++;
    }
  }
  sort(res.begin(),res.end());
  res.erase(unique(res.begin(),res.end()),res.end());
  cout << res[k] << endl;
  return 0;
}