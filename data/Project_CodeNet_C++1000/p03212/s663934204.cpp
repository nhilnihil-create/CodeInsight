#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <bitset>
#include <numeric>
#include <array>
#include <cstring>
#include <random>
#include <chrono>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string n;
int nlen, ans = 0;
void gen(string cur, int len, int am7, int am5, int am3) {
  if(len > nlen) return;
  if(len && am3 && am5 && am7) ans += (stoi(cur) <= stoi(n));
  gen(cur + '3', len + 1, am7, am5, am3 + 1);
  gen(cur + '5', len + 1, am7, am5 + 1, am3);
  gen(cur + '7', len + 1, am7 + 1, am5, am3);
}
int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;

  nlen = n.size();

  gen("", 0, 0, 0, 0);

  cout << ans;

  return 0;
}
/*

*/
