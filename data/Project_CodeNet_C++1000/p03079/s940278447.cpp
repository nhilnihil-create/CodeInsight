#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repe(i, n) for (int i = 0; i <= (n); ++i)
#define repe1(i, n) for (int i = 0; i <= (n); ++i)
#define all(x) (x).begin(),(x).end()
#define pb(x) push_back(x)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
const int INF = 1e9;
const ll mod = 1000000007;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if (a==b && a==c && b==c) {
    cout << "Yes" << "\n";
  } else {
    cout << "No" << "\n";
  }
}
