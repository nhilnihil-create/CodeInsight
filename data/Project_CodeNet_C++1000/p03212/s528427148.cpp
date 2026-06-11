#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

bool chk(ll n)
{
    map<char,ll> C;
    string s = to_string(n);
    REP(i,0,SZ(s)) ++C[s[i]];
    if(C['3']*C['5']*C['7'] > 0) return true;
    else return false;
}

int main()
{
    ll N;
    cin >> N;

    vec A;
    ll k = 0;
    A.pb(3);
    A.pb(5);
    A.pb(7);
    while(true) {
        A.pb(A[k]*10+3);
        A.pb(A[k]*10+5);
        A.pb(A[k]*10+7);
        ++k;
        if(A.back() > 1000000000LL) break;
    }

    ll cnt = 0;
    REP(i,0,SZ(A)) {
        if(A[i] > N) break;
        if(chk(A[i])) ++cnt; 
    }
    PR(cnt);

    return 0;
}

/*



*/