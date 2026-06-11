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
    vec A(N), B(N);
    REP(i,0,N) cin >> A[i];
    REP(i,0,N) cin >> B[i];

    ll sumA = 0, sumB = 0;
    REP(i,0,N) {
        sumA += A[i];
        sumB += B[i];
    }

    if(sumA < sumB) PR(-1);
    else {
        vec D(N, 0);
        ll cnt = 0, sum = 0;
        REP(i,0,N) {
            if(A[i] < B[i]) {
                sum += B[i] - A[i];
                ++cnt;
            }
            else D[i] = A[i] - B[i];
        }
        DESC(D);
        REP(i,0,N) {
            if(sum >= D[i]) {
                ++cnt;
                sum -= D[i];
            }
            else if(sum > 0){
                ++cnt;
                break;
            }
            else break;
        }
        PR(cnt);
    }

    return 0;
}

/*

A 2 3 5
B 3 4 1

D 1 1 0
E 0 0 4

*/