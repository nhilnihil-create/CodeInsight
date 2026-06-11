#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return __gcd(a,b); } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最小公倍数

int main() {
  int N,K;
  cin>>N>>K;
  if((N+1)/2 >= K){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }}