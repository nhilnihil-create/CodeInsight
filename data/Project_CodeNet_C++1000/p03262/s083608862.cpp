#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
ll gcd(ll a,ll b){
  if (b==0) return a;
  else return gcd(b,a%b);
}

int main(){
  ll n,X;
  cin >> n >> X;
  vector<ll> x(n);
  rep(i,n){
    int y; cin >> y;
    x.at(i) = abs(X-y);
  }

  sort(all(x));

  ll ans = x.at(0);

  for(int i=0;i<n;i++){
    ans = gcd(ans,x.at(i));
  }

  cout << ans << endl;


}