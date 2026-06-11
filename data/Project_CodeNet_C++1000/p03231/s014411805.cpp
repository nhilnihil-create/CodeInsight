#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template < typename T > string tost( const T& n ) { ostringstream stm; stm << n; return stm.str();}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

ll N,M;
string S,T;
cin >> N >> M >> S >> T;

ll G = gcd(N, M);
ll L = N / G * M;

rep(i,G) {
    if(S[L/M*i] != T[L/N*i]) {
        cout << -1 << endl;
        return 0;
    }
}
cout << L << endl;
return 0;
}