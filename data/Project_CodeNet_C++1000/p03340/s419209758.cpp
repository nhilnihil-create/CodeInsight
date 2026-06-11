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

int main(){
  int N; cin >> N;
  vector<ll> A(N); rep(i,N) cin >> A[i];
  vector<ll> ss(N+1,0);
  rep(i,N) ss[i+1] = ss[i] + A[i];
  vector<ll> xs(N+1,0);
  rep(i,N) xs[i+1] = xs[i] ^ A[i];

  ll ans = 0;
  int r=1;
  for(int l=0;l<N;l++){
    ll p = ss[r]-ss[l];
    ll x = xs[r]^xs[l];
    //cout << l << " " << r << " " << p << " " << x << endl;
    for(;r<=N;r++){
      if(r==N){
        ll w = r-l;
        ans += w*(w+1)/2;
        l=1e9;
        break;
      }
      p += A[r];
      x ^= A[r];
      if(p!=x){
        ll w = r-l;
        ans += w;
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
