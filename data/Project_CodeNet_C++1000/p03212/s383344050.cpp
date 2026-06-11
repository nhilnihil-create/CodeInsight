#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void DFS(ll x, int n, int& ans)
{
  if (n<x) return;
  
  string tmp = to_string(x);
  map<char, int> mp;
  
  for (int i=0; i<tmp.size(); i++) {
    if (mp.count(tmp[i])) {
      mp[tmp[i]]++;
    }
    else mp[tmp[i]] = 1;
  }
  if (mp.size() == 3) ans++;
  
  DFS(x*10+3, n, ans);
  DFS(x*10+5, n, ans);
  DFS(x*10+7, n, ans);
}

int main(){
  int n, ans=0;
  cin >> n;
  vector<int>a;
  DFS(0, n, ans);
 
  cout << ans << endl;
}
