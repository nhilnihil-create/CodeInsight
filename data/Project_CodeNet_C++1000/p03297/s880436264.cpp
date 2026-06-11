#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 987654321;
const ll MOD = 1000000007;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main(void) {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  //freopen("in.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    //cout << A << B << C << D << endl;
    if(A < B) {
      cout << "No" << endl;
      continue;
    } else if(B > D) {
      cout << "No" << endl;
      continue;
    } else if(B <= D && B <= C) {
      cout << "Yes" << endl;
      continue;
    }

    // B <= D && B > C case
    ll a,d;
    ll b,c;

    a = A % B;
    d = D % B;
    ll g = gcd(B, D);

    if(g == B) {
      if(a > C) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    } else {
      if(a > C) {
        cout << "No" << endl;
        continue;
      }
      c = (C - a) / g;
      b = (B - a) / g;
      if((B-a)%g) {
        b++;
      }
      if(c+1 < B && b-c > 1) {
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    }
  }
  return 0;
}
