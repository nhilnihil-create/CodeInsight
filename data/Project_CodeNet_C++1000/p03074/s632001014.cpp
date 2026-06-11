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

int main()
{
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    S += "*";

    vec zero, one;
    ll p = 0, c;
    if(S[0] == '0') one.pb(0);
    while(p < N) {
        c = 1;
        while(S[p] == S[p+1]) {
            ++c;
            ++p;
        }
        if(S[p] == '0') zero.pb(c);
        else one.pb(c);
        ++p;
    }
    if(S[N-1] == '0') one.pb(0);

    if(SZ(zero) < K) PR(N);
    else {
        ll sum = one[0], m;
        REP(i,0,K) sum += zero[i] + one[i+1];
        m = sum;
        REP(i,0,SZ(zero)-K) {
            sum = sum - (zero[i] + one[i]) + (zero[i+K] + one[i+1+K]);
            m = MAX(m,sum);
        }
        PR(m);
    }

    return 0;
}

/*



*/