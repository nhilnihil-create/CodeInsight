#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i=0; i<(ll)n; i++)
#define REPR(i, n) for(ll i=(ll)n-1; i>=0; i--)
#define FOR(i, m, n) for(ll i=(ll)m; i<(ll)n; i++)
#define FORR(i, m, n) for(ll i=(ll)m-1; i>=(ll)n; i--)
#define ALL(x) (x).begin(), (x).end()
#define ASC(v) sort(ALL(v));
#define DESC(v) sort(ALL(v), greater<int>());
#define UNIQ(a) sort(ALL(a));(a).resize(unique(ALL(a)) - a.begin());
#define PRINTD(x, d) cout << fixed << setprecision(d) << x << "\n";
#define DEBUG(x) cout<<#x<<": "<<x<<"\n"
const double PI = acos(-1);
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
bool isprime(int x){ int i; if(x<2)return 0; else if(x==2) return 1; if(x%2==0) return 0; for(i=3; i*i<=x; i+=2) if(x%i==0) return 0; return 1; }
int digsum(int n) { int r=0; while(n>0) { r+=n%10; n/=10; } return r; }
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
 
int main(){
    vector<ll> A(3);
    REP(i, 3) cin >> A[i];
    ASC(A);
    cout << A[1]-A[0] + A[2]-A[1] << "\n";
}
