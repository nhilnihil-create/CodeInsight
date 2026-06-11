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
    cin >> N;
    vec X(N+1, 0), Y(N+1, 0);
    REP(i,1,N+1) {
        cin >> X[i];
        Y[i] = X[i];
    }

    ASC(Y);
    REP(i,1,N+1) {
        if(X[i] <= Y[N/2]) PR(Y[N/2+1]);
        else PR(Y[N/2]);
    }


    return 0;
}

/*

1 2 3 4 5 6 7 8

1 2 4 5 6 7 8
1 3 4 5 6 7 8
1 2 3 4 5 7 8
2 3 4 5 6 7 8
1 2 3 4 5 6 7
*/