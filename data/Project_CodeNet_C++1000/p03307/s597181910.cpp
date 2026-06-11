#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

#define FOR(i,m,n) for(ll (i)=(m); (i)<(ll)(n); ++(i))
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin,(a).end

ll gcd(ll a, ll b){
  return a%b ? gcd(b, a%b) : b;
}

ll lcm(ll a, ll b){
  return a / gcd(a, b) * b; // prevent from overflowing
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n; cin >> n;
  cout << lcm(n, 2) << endl;
  return 0;
}