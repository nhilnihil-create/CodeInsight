#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;

int main(){
  vector<ll> v(5);
  ll k; cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> k;
  rep(i,5){
    for(ll j=i+1; j<5; j++){
      if(abs(v[i]-v[j])>k){
        cout << ":(";
        return 0;
      }
    }
  }
  cout << "Yay!";
  return 0;
}
