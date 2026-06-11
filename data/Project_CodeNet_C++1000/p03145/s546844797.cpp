#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  ll a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);

  priority_queue<ll, vector<ll>, greater<ll>> que;  // -> 0,1,2,...
  que.push(a);
  que.push(b);
  que.push(c);

  ll v1 = que.top();
  que.pop();
  ll v2 = que.top();
  que.pop();

  cout << (v1 * v2 / 2) << endl;
}
