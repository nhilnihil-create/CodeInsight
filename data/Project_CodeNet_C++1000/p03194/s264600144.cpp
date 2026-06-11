#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;

vector<pair<ll, ll> > v;

int main()
{
  ll n, p;
  cin >> n >> p;

  if(n == 1){
    cout << p << endl;
    return 0;
  }

  if(n >= 40){
    cout << 1 << endl;
    return 0;
  }

  ll ans = 1;
  for(ll i = 2;;){
    ll po = pow(i, n);
    if(po > p){
      break;  
    }else if(p % po == 0){
      p /= po;
      ans *= i;
    }else{
      i++;
    }
  }

  cout << ans << endl;

  return 0;
}

