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

    vec A(26, 0);
    REP(i,0,SZ(S)) A[S[i]-'a'] = i + 1;
    if(SZ(S) < 26) {
        ll k = 0;
        while(A[k] > 0) ++k;
        PR(S+(char)(k+'a'));
    }
    else {
        ll k = 25;
        while(k > 0 && S[k-1] > S[k]) --k;
        if(k > 0) {
            char c = 'z';
            REP(i,k,26) {
                if(S[i] > S[k-1]) c = MIN(c,S[i]);
            }
            PR(S.substr(0,k-1)+c);
        }
        else PR(-1);
    }

    return 0;
}

/*

*/ 