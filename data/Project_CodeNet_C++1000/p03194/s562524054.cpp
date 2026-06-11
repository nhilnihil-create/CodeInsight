#include<iostream>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;
typedef long long ll;

int main(void){
  ll n,p;
  cin >> n >> p;
  if( n == 1){
    cout << p << endl;
    return 0;
  }
  vector< pair<ll, ll> > factor(sqrt(p));
  for( ll i=2; i<= sqrt(p); ++i){
    ll count = 0;
    while( (p % i) == 0){
      ++count;
      p /= i;
    }
    if( count != 0){
      factor.push_back(make_pair(i, count));
    }
  }
  ll ret=1;
  for( vector< pair<ll, ll> >::iterator itr=factor.begin(); itr!=factor.end(); ++itr){
    //if( (*itr).second > 0) cout << (*itr).second / n << endl;
    if( ((*itr).second / n) >= 1){
      ret *= (ll)pow(((*itr).first),((*itr).second / n))  ;
    }
  }
  cout << ret << endl;
  return 0;
}
