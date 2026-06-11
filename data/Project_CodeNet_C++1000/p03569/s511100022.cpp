#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define P pair<ll,ll> 
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s,t;cin>>s;
  ll len=s.length(),l=0,r=len-1,x_to_add=0;
  bool is_possible=true;
  while(l<r) {
    if(s[l]==s[r]) {l++,r--;}
    else {
      if(s[l]=='x') {l++;x_to_add++;}
      else if(s[r]=='x') {r--;x_to_add++;}
      else {is_possible=false;break;}
    }
    if(!is_possible) break;
  }
  if(is_possible) print(x_to_add);else print(-1);
  return 0;
}