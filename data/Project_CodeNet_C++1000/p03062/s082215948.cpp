#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;


int main(){
  int n;
  cin >>n;
  ll a[n];
  int minus=0;
  ll g=10000000000;
  rep(i,n){
    cin >> a[i];
    if(a[i]<0)minus++;
    chmin(g,abs(a[i]));
  }
  ll ans=0;
  if(minus%2==0){
    rep(i,n)ans+=abs(a[i]);
    cout << ans <<endl;
  }else{
    rep(i,n)ans+=abs(a[i]);
    ans-=g*2;
    cout << ans << endl;
  }
}