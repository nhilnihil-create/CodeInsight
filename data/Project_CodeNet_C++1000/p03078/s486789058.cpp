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
  ll X, Y, Z, K; cin >> X >> Y >> Z >> K;
  vector<ll> A(X); rep(i,X) cin >> A[i];
  vector<ll> B(Y); rep(i,Y) cin >> B[i];
  vector<ll> C(Z); rep(i,Z) cin >> C[i];
  sort(rall(A));
  sort(rall(B));
  sort(rall(C));
  vector<ll> rank;
  rep(x,X){
    rep(y,Y){
      rank.pb(A[x]+B[y]);
    }
  }
  sort(rall(rank));
  rank.resize(K);
  vector<ll> rank2;
  rep(k,K){
    rep(z,Z){
      rank2.pb(rank[k]+C[z]);
    }
  }
  sort(rall(rank2));
  rep(i,K) cout << rank2[i] << '\n';
  return 0;
}
