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

bool isp(int x){
  for(int i=2;i*i<=x;i++){
    if(x%i==0) return false;
  }
  return true;
}

void solve(){
  vector<int> ok(100010,0);
  for(int i=3;i<=100000;i+=2){
    ok[i] = isp(i)&isp((i+1)/2);
  }
  vector<ll> sums(100010+1,0);
  rep(i,100010) sums[i+1] = sums[i] + ok[i];
  int Q; cin >> Q;
  rep(q,Q){
    int l, r; cin >> l >> r;
    r++;
    cout << sums[r]-sums[l] << '\n';
  }
}

int main(){
  solve();
  return 0;
}
