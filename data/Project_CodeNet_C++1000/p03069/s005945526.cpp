#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  int n;
  string s;
  cin >> n >> s;
  int b = 0,w = 0;
  for(int i = 0;i < n;i++)w += (s[i] == '.');
  ll res = 1ll << 60;
  res = min(res,w*1ll);
  for(int i = 0;i < n;i++){
    if(s[i] == '#')b++;
    else w--;
    res = min(res,b+w*1ll);
  }
  res = min(res,b*1ll);
  cout << res << endl;






  return 0;
}