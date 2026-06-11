#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll solve(ll X){
    ll ret = 0;
    ll base = 1;
    for(int b = 0; b < 60; b++){
        ll next = base * 2;
        ll n = 0;
        n += base * (X / next);
        ll r = X % next;
        n += max(0LL, r - base + 1);
        if(n%2)
            ret += 1LL << b;
        base = next;
    }
    return ret;
}

int main(){
    ll A, B;
    cin >> A >> B;
    ll a = solve(A-1);
    ll b = solve(B);
    ll ans = a ^ b;
    //cout << a << endl;
    //cout << b << endl;
    cout << ans << endl;
    return 0;
}
