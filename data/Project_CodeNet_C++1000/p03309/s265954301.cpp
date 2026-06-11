#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;
const int MOD = 1000000007;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) {
    cin >> a[i];
  }

  vector<ll> a2(n);
  rep(i,n) {
    a2[i] = a[i] - (i+1);
  }
  sort(a2.begin(), a2.end());

  ll b = a2[n/2];

  ll result = 0;
  rep(i,n) {
    result += abs(a[i] - b - (i+1));
  }

  cout << result << endl;
}
