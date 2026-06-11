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
  vector<ll> p(5);
  ll m = INFL;

  rep(i,5){
    cin >> p.at(i);
    m = min(m,p.at(i));
  }

  cout << (n-1)/m + 5 << endl;
}
