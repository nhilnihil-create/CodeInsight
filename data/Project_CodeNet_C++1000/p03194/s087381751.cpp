#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long int ll;
ll cnt=0;
bool is_prime(ll n) {
    if(n == 1) return false; // 1 は素数ではない。
    for(ll i = 2; i*i <= n; ++i) { // 2 <= i <= sqrt(n) に約数があれば、
        if(n % i == 0) return false; // n は素数ではない
    }
    return true;
}
std::pair<std::vector<ll>, std::vector<ll>> prime_factor_decomp(ll n) {
    std::vector<ll> p, e;
    ll m = n;
    for (ll i = 2; i * i <= n; i++) {
        if (m % i != 0) continue;
        int c = 0;
        while (m % i == 0) c++, m /= i;
        p.push_back(i);
        e.push_back(c);
        cnt++;
    }
    if (m > 1) {
        p.push_back(m);
        e.push_back(1);
        cnt++;
    }
    return std::make_pair(p, e);
}
int main(){
  ll n,p;
  cin >>n>>p;
  if(n==1) cout<<p<<endl;
  else if(is_prime(p)) cout <<1<<endl;
  else{
    pair <vector<ll>,vector<ll>> v=prime_factor_decomp(p);
    ll ans=1;
    for(ll i=0;i<cnt;i++){
      if(v.second[i]>=n){
        ll k=v.second[i]/n,p=1;
        for(ll j=0;j<k;j++) p*=v.first[i];
        ans*=p;
      }
    }
    cout <<ans<<endl;
  }

}
