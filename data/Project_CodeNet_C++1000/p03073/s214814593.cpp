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

    ll cnt1 = 0, cnt2 = 0, N = SZ(S);
    REP(i,0,N) {
        if(S[i] == '0' && i % 2 == 0) ++cnt1;
        else if(S[i] == '1' && i % 2 == 1) ++cnt1;
        else if(S[i] == '0' && i % 2 == 1) ++cnt2;
        else ++cnt2;
    }
    PR(MIN(cnt1,cnt2));

    return 0;
}

/*



*/