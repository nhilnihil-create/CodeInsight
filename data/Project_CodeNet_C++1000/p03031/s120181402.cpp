#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,b,bb;
  cin >> n >> m;
  vector<int>p(m);
  vector<vector<int>>a(m);
  for(int i=0;i<m;i++){
    cin >> b;
    for(int j=0;j<b;j++){
      cin >> bb;
      a.at(i).push_back(bb-1);
    }
  }
  for(int i=0;i<m;i++)
    cin >> p.at(i);
  bool ok=false;
  int ans=0;
  for(int i=0,l=(1<<n);i<l;i++){
    bitset<10>ptn=i;
    ok=true;
    for(int j=0;j<m;j++){
      int c=0;
      for(int k=0;k<a.at(j).size();k++)
        if(ptn.test(a.at(j).at(k))) c++;
      if(c%2!=p.at(j))
        ok=false;
    }
    if(ok) ans++;
  }
  cout << ans << endl;
  return 0;
}