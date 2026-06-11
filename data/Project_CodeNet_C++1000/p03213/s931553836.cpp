#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  vector<ll> p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
  ll N; cin >> N;
  map<ll, ll> count;
  for (ll n = 2; n <= N; n++) {
    for (ll i = 0; i < 15; i++) {
      ll pow = 0;
      ll num = n;
      while (num % p[i] == 0) {num/=p[i]; pow++;}
      count[p[i]] += pow;
    }
  }
  ll g3 = 0, g5 = 0, g15 = 0, g25 = 0, g75 = 0;
  for (ll i = 0; i < 15; i++) {
    if (count[p[i]] >= 74) {g3++; g5++; g15++; g25++; g75++;}
    else if (count[p[i]] >= 24) {g3++; g5++; g15++; g25++;}
    else if (count[p[i]] >= 14) {g3++; g5++; g15++;}
    else if (count[p[i]] >= 4) {g3++; g5++;}
    else if (count[p[i]] >= 2) {g3++;}
  }
  ll res = 0;
  res += g75;
  if (g25 > 0) {res += (g3-1)*g25;}
  if (g15 > 0) {res += (g5-1)*g15;}
  if (g5 > 1) {res += (g3-2)*g5*(g5-1)/2;}
  cout << res << endl;  
}