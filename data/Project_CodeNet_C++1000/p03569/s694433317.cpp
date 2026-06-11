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
    string S;
    cin >> S;

    ll N = SZ(S);
    string T;
    REP(i,0,N) {
        if(S[i] != 'x') T.pb(S[i]);
    }

    bool f = true;
    REP(i,0,SZ(T)) {
        if(T[i] != T[SZ(T)-i-1]) f = false;
    }

    if(f) {
        S = "*" + S + "*"; 
        ll L = (SZ(T) + 1) / 2, R = (SZ(T) + 1) / 2;
        ll left = 0, right = N+1;
        while(L > 0) {
            ++left;
            if(S[left] != 'x') --L;
        }
        while(R > 0) {
            --right;
            if(S[right] != 'x') --R;
        }

        ll cnt = 0;
        while(left >= 1 && right <= N) {
            ll cl = 0, cr = 0;
            --left;
            ++right;
            while(S[left] == 'x') {
                ++cl;
                --left;
            }
            while(S[right] == 'x') {
                ++cr;
                ++right;
            }
            cnt += abs(cl - cr);
        }
        PR(cnt);
    }
    else PR(-1);

    return 0;
}

/*



*/