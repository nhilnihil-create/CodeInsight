#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }

int main() {
  int T; cin >> T;
  rep(i,T) {
    ll A, B, C, D; cin >> A >> B >> C >> D;
    if (A<B) { cout << "No" << endl; continue; }
    if (B>D) { cout << "No" << endl; continue; }
    if (C>=B) { cout << "Yes" << endl; continue; }
    if (D%B==0) {
      string result = (A%B<=C) ? "Yes" : "No";
      cout << result << endl; 
      continue;
    }
    ll gbd = gcd(B,D);
    string result = ((B-gbd)+A%gbd<=C) ? "Yes" : "No";
    cout << result << endl;
  }
  return 0;
}