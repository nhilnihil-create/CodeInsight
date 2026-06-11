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
  vector<ll> B(N+1,0);
  rep(i,N) B[i+1] = gcd(B[i],A[i]);
  vector<ll> C(N+1,0);
  rep(i,N) C[N-i-1] = gcd(C[N-i],A[N-i-1]);

  ll ans = 0;
  rep(i,N) {
    //cout << B[i] << " " << C[i+1] << endl;
    chmax(ans, gcd(B[i],C[i+1]));
  }
  cout << ans << endl;
  return 0;
}
