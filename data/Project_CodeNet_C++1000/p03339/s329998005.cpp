#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for( ll i = 0;i < (ll) n;++i)

int main(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll E = count(s.begin(),s.end(),'E');
  ll W = count(s.begin(),s.end(),'W');
  ll mn = s.size();
  ll e=0,w=0;
  rep(i,n){
    ll cnt = w + ( E - e );
    if( s[i] == 'E' ){
      e++;
      cnt--;
    }
    if( s[i] == 'W' ) w++;
    if( cnt < mn ){
      mn = cnt;
    }
  }
  cout << mn << endl;
      
  return 0;
}