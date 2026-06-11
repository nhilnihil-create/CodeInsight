#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

string as = "AKIHABARA";

int main(void)
{
  string s;
  cin >> s;
  ll cnt = 0;
  REP(i, as.size()) {
    if(s[i] != as[i]) {
      if(as[i] == 'A') {
	s.insert(cnt, "A");
      } else {
	cout << "NO" << endl;
	return 0;
      }
    }
  }
  if(s.size() == as.size()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
