#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){

  string s;
  cin >> s;
  string t = "";
  rep(i,s.size())if(s[i] != 'x')t += s[i];
  for(int i = 0,j = (int)t.size()-1;i < j;i++,j--){
    if(t[i] != t[j]){
      cout << -1 << endl;
      return 0;
    }
  }
  ll l = 0,r = 0;
  ll res = 0;
  for(ll i = 0,j = s.size()-1;i < j;i++,j--){
    ll sl = 0,sr = 0;
    for(int k = i;s[k] == 'x';k++){
      sl++;
      i = k;
    }
    for(int k = j;s[k] == 'x';k--){
      sr++;
      j = k;
    }
    if(i < j)res += abs(sl-sr);
    if(sl)i++;
    if(sr)j--;
  }
  cout << res << endl;





  return 0;
}