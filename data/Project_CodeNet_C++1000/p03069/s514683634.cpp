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
    ll N;
    string S;
    cin >> N >> S;
    
    ll left = 0, right = N - 1;
    while(left < N && S[left] == '.') ++left;
    while(right >= 0 && S[right] == '#') --right;

    if(left < right) {
        vec B(N, INF), W(N, INF);
        ll c = 0;
        REP(i,left,right+1) {
            if(S[i] == '#') ++c;
            B[i] = c;   
        }
        c = 0;
        for(ll i=right; i>=left; --i) {
            if(S[i] == '.') ++c;
            W[i] = c;   
        }

        ll m = INF;
        REP(i,left,right) {
            ll a = B[i] + W[i+1];
            ll b = B[i+1] + W[i];
            m = MIN(m,MIN(a,b));
        }
        m = MIN(m,MIN(W[left],B[right]));
        PR(m);
    }
    else PR(0);

    return 0;
}

/*



*/