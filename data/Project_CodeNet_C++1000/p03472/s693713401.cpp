#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
#define MOD 1000000007
int main()
{   
  int n, h;
  cin >> n >> h;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
 
  int max_a = *max_element(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());
  ll d = 0;
  int natk = 0;
  rep(i, n) {
    if (d >= h) {
      printf("%d\n", natk);
      return 0;
    }
    if (b[i] <= max_a) break;
    d += b[i];
    ++natk;
  }
  natk += (h - d + max_a - 1) / max_a;
  printf("%d\n", natk);
  return 0;
}