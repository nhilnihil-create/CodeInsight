#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <stdio.h>
#include <unistd.h>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define drep(i, n) for(int i = n - 1; i >= 0; i--)
#define itrep(itr, base) for (auto itr = base.begin(); itr != base.end(); itr++)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl
#define PI 3.14159265359

const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;
const int mod = 1000000007;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

vector<set<int>> mp;
vector<pair<int, int>> v;
vector<int> reach;

int solve(int now) {
  itrep(itr, mp[now]) {
    if (reach[*itr] == 0) {
      reach[*itr] = 1;
      solve(*itr);
    }
  }
  return 1;
}

int main() {
  int n, m;
  cin >> n >> m;
  mp = vector<set<int>>(n);
  rep (i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    v.push_back(make_pair(a, b));
    mp[a].insert(b);
    mp[b].insert(a);
  }

  int ans = 0;
  rep (i, m) {
    int a, b;
    a = v[i].first;
    b = v[i].second;
    mp[a].erase(mp[a].find(b));
    mp[b].erase(mp[b].find(a));
    reach = vector<int>(n, 0);
    reach[a] = 1;
    solve(a);
    int flag = 0;
    rep (i, n) {
      if (reach[i] == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      // cout << "bridge: " << a << " => " << b << endl;
      ans++;
    }
    mp[a].insert(b);
    mp[b].insert(a);
  }
  P(ans);

  return 0;
}

