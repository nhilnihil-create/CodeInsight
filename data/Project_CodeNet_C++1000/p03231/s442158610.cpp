#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

ll gcd(ll a,ll b){
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b,a%b);
    }
}

ll lcm(ll x, ll y) {
    return x / gcd(x,y) * y;
}

int main(void)
{
    IOS
    int N, M;
    cin >> N >> M;
    string S; cin >> S;
    string T; cin >> T;

    ll xl = lcm(N,M);
    ll ln = xl / N;
    ll lm = xl / M;

    if (N == M && S != T) {
        OUT(-1)
        return 0;
    } else {
        map<ll,char> X;
        REP(i,N) {
            X[ln*i] = S[i];
        }
        REP(i,M) {
            if (!(X.count(lm*i) == 0 || X[lm*i] == T[i])) {
                OUT(-1)
                return 0;
            }
        }
    }

    cout << xl << '\n';

    return 0;
}
