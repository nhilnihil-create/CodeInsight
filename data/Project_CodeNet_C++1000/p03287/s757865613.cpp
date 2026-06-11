#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <ios>
#include <ctype.h>
#include <stack>
#include <istream>
#include <stdio.h>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <list>
#include <deque>
#include <time.h>
#include <random>
#include <iomanip>
#include <fstream>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define pint pair<int,int>
const int INF = 1000000007;
const long double EPS = 1e-15;
const long double PI = acos(-1);
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
using Graph_weighted = vector<vector<pair<int,int>>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
int main(){
  ll n,m;
  cin >> n >> m;
  map<ll,ll>cnt;
  vector<ll>v(n),sum(n + 1);
  rep(i,n)cin >> v[i];
  rep(i,n)sum[i + 1] = sum[i] + v[i];
  rep(i,n + 1){
    cnt[sum[i] % m]++;
  }
  ll ans = 0;
  for(auto i : cnt){
    if(i.second >= 2){
      ans += (i.second * (i.second - 1)) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
