#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<string> s(n);
  rep(i,n){
    cin >> s.at(i);
  }
  ll ans=0;
  rep(i,n){
    rep(j,s.at(i).size()-1){
      if(s.at(i).at(j)=='A' && s.at(i).at(j+1)=='B'){
        ans++;
      }
    }
  }
  ll p=0,q=0,r=0;
  rep(i,n){
    ll l=s.at(i).size();
    if(s.at(i).at(0)== 'B' &&s.at(i).at(l-1)=='A'){
      p++;
    }else if(s.at(i).at(0)=='B'){
      q++;
    }else if(s.at(i).at(l-1)=='A'){
      r++;
    }
  }
  ll cp=0;
  ll x=max(p-1,cp);
  if(p>0&&q>0){
    ans++;
    q--;
  }
  if(p>0&&r>0){
    ans++;
    r--;
  }
  x+=min(q,r);
  cout << ans+x;
}