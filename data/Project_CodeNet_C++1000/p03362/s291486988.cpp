#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int prime[100010];
bool isprime[100010];

int sieve(int n)
{
  int p=0;
  for (int i=0; i<=n; i++) isprime[i] = true;
  isprime[0] = isprime[1] = false;
  for (int i=2; i<n; i++) {
    if (isprime[i]) {
      prime[p++] = i;
      for (int j=2*i; j<=n; j+=i) isprime[j] = false;
    }
  }
  return p;
}

int main()
{
  int n; cin >> n;
  sieve(100000);
  int i = 0;
  vector<int> ans;
  while ((int)ans.size() < n) {
    if (prime[i]%5 == 1) ans.push_back(prime[i]);
    i++;
  }
  for (int i=0; i<n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
