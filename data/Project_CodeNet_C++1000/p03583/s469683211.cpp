#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int const INF = 1001001001;


int main()
{
    ll n;
    cin >> n;
    for(ll x = 1; x <= 3500; x++) {
        for(ll y = 1; y <= 3500; y++) {
            if(4*x*y - n*y - n*x == 0) continue;
            if((n*x*y) % (4*x*y - n*y - n*x) == 0) {
                ll z = (n*x*y) / (4*x*y - n*y - n*x);
                if(z > 0) {
                    cout << x << ' ' << y << ' ' << z << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}