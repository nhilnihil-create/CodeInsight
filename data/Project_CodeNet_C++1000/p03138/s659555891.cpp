#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <fstream>
#include <chrono>
#include <random>
#include <bitset>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((int)(x).size())
#define pb push_back
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}

ll mpow(ll a, ll x){
  ll res = 1;
  while(x > 0){
    if(x & 1) res = (res * a);
    a = (a * a);
    x >>= 1;
  }
  return res;
}

int main(){
  ll N, K; cin >> N >> K;
  vector<ll> A(N); rep(i,N) cin >> A[i];
  vector<int> cnt(40,0);
  rep(i,N){
    ll now = A[i];
    rep(j,40){
      cnt[j] += now&1;
      now >>= 1;
    }
  }
  reverse(all(cnt));
  //rep(i,40) cout << cnt[i];
  //cout << endl;
  vector<int> k(40,0);
  ll kk = K;
  rep(i,40){
    k[i] = kk & 1;
    kk >>= 1;
  }
  reverse(all(k));
  //rep(i,40) cout << k[i];
  //cout << endl;
  ll x=0;
  bool f = false;
  rep(i,40){
    ll pre = (cnt[i]*2<=N)?1:0;
    if(k[i]==0 && (!f)){
      pre = 0;
    }
    if(pre==0 && k[i]==1){
      f = true;
    }
    x += pre * mpow(2,39-i);
  }
  //cout << x << endl;
  ll ans = 0;
  rep(i,N){
    ans += x^A[i];
  }
  cout << ans << endl;
}
