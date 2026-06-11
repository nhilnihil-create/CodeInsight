#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
  ll x,y;
  cin>>x>>y;
  ///////////
  ll a=x;
  ll ans=1;
  while(a<=y){
    
    a*=2;
    if(a<=y){
    ans++;}
  }
  cout<<ans<<endl;
}

