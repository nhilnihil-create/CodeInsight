#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

ll gcd_euclid(ll u, ll v) {
  ll r;
  while (0 != v) {
    r = u % v; u = v; v = r; /* swap */
  }
  return u;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        if(b>a){
            cout << "No" << endl;
            continue;
        }
        if(b>d){
            cout << "No" << endl;
            continue;
        }
        if(c>=b){
            cout << "Yes" << endl;
            continue;
        }
        ll g=gcd_euclid(b,d);
        if(b-g+a%g>c){
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;

    }


    
}