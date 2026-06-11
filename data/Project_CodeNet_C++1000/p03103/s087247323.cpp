// #include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <math.h>
#include <map>
#include <queue>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define REP(i,n)   FOR(i,0,n)
#define RREP(i,n)   RFOR(i,0,n)
#define SORT(s) sort(s.begin(), s.end())
#define P pair<int, int>
#define mp make_pair

const double INF = 1e+09;
const int MOD = 1e9+7;

using namespace std;




// printf("%.10f\n" , ans);
int main(void){
  ios::sync_with_stdio(false);
 ll n, m;
 cin >> n >> m;
 vector<pair<ll, ll>> p(n);
 REP(i, n){
   ll a, b;
   cin >> a >> b;
   p[i].first = a;
   p[i].second = b;
 }
 sort(p.begin(), p.end());
 ll ans = 0;
 ll now = 0;
 while (now < m){
   for (auto v : p){
     ll val = v.second;
     val = min(m-now, val);
     ans += val * v.first;
     now += val;
   }
 }
 cout << ans << endl;
  return 0;
}

