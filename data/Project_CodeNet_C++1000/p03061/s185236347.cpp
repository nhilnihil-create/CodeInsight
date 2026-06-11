#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define MOD 1000000007

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> undergcd(n);
  vector<ll> overgcd(n);
  vector<ll> allgcd(n);
  rep(i, n) cin >> a[i];
  sort(ALL(a));
  undergcd[0] = a[0];
  overgcd[n - 1] = a[n - 1];
  for (int i = 1; i < n; i++) {
    undergcd[i] = __gcd(undergcd[i - 1], a[i]);
    overgcd[n - 1 - i] = __gcd(overgcd[n - i], a[n - 1 - i]);
  }
  allgcd[0] = overgcd[1];
  allgcd[n - 1] = undergcd[n - 2];
  for (int i = 1; i < n - 1; i++) {
    allgcd[i] = __gcd(undergcd[i - 1], overgcd[i + 1]);
  }
  sort(ALL(allgcd));
  cout << allgcd[n - 1] << endl;

  return 0;
}
