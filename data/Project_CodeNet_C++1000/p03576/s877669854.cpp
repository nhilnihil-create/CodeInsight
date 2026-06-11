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
#define mod 1000000007
using ll = long long;
using namespace std;
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}

int main(){
  int N, K; cin >> N >> K;
  vector<pair<ll,ll>> XY(N); rep(i,N) cin >> XY[i].first >> XY[i].second;
  ll ans = 4e18+1e15;
  rep(i,N){
    rep(j,N){
      rep(k,N){
        rep(l,N){
          ll x1 = XY[i].first;
          ll x2 = XY[j].first;
          ll y1 = XY[k].second;
          ll y2 = XY[l].second;
          ll xmin = min(x1, x2);
          ll xmax = max(x1, x2);
          ll ymin = min(y1, y2);
          ll ymax = max(y1, y2);
          ll S = (xmax-xmin)*(ymax-ymin);
          int cnt = 0;
          rep(n,N){
            ll xn = XY[n].first;
            ll yn = XY[n].second;
            if(xmin<=xn && xn<=xmax && ymin<=yn && yn<=ymax) cnt++;
          }
          if(cnt >= K) ans = min(ans,S);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
