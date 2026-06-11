#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());

int main(){
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  map<string,int> mp;
  for(int i=0;i<=n-1;i++){ //始点
    for(int j=1;j<=n-i;j++){ //いくつ取り出すか
      string tmp = s.substr(i,j);
      if(tmp.size() <= k) mp[tmp] ++;
    }
  }
  vector<string> l(0);
  for(auto p : mp) l.push_back(p.first);
  sort(l);
  cout << l[k-1] << endl;
}