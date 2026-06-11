#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;

int main(){
  ll n; cin >> n;
  vector<ll> x(n);
  vector<ll> y(n);
  rep(i,n){
    ll a; cin >> a;
    x.at(i) = y.at(i) = a;
  }

  sort(all(y));
  ll left = y.at(n/2-1),right = y.at(n/2);

  rep(i,n){
    ll b;
    if(x.at(i)>=right) b = left;
    else b = right;

    cout << b << endl;
  }
}
