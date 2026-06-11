// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll h,w,n,sr,sc;
  string s,t;
  bool can = true;
  cin >> h >> w >> n >> sr >> sc >> s >> t;
  sr--;
  sc--;
  ll l=0,r=w;
  if(s.back()=='L') l++;
  if(s.back()=='R') r--;
  for(int i=n-2;i>=0;i--){
    if(t[i]=='L') r = min(r+1,w);
    if(t[i]=='R') l = max(0ll,l-1);

    if(s[i]=='L') l++;
    if(s[i]=='R') r--;
    if(l>=r) can = false;
  }
  if(l>sc||sc>=r) can = false;
  l=0,r=h;
  if(s.back()=='U') l++;
  if(s.back()=='D') r--;
  for(int i=n-2;i>=0;i--){
    if(t[i]=='U') r = min(r+1,h);
    if(t[i]=='D') l = max(0ll,l-1);

    if(s[i]=='U') l++;
    if(s[i]=='D') r--;
    if(l>=r) can = false;
  }
  if(l>sr||sr>=r) can = false;

  if(can) cout <<"YES\n";
  else cout <<"NO\n";
}
