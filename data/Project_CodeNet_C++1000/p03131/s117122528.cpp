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
    ll K, A, B;
    cin >> K >> A >> B;
    
    ll ans = 0;
    if(A+1 <= K) {
        if(A+2 < B) {
            if((K-A-1)%2 == 0) ans = B + (B-A) * ((K-A-1) / 2);
            else ans = B + (B-A) * ((K-A-1) / 2) + 1;
        }
        else ans = K + 1;
    }
    else ans = K + 1;

    PR(ans);
    
    return 0;
}

/*

[1] x -> x+1
[2] x -> x-A
[3] x -> x+B

*/