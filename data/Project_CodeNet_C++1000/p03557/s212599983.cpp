#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    REP(i, N) cin >> A[i];
    REP(i, N) cin >> B[i];
    REP(i, N) cin >> C[i];

    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(C));

    ll ans = 0;

    vector<ll> B_choice(N);
    REP(i, N) {
        auto itr_c = upper_bound(C.begin(), C.end(), B[i]);
        if(itr_c == C.end()) continue;
        B_choice[i] = N - (itr_c - C.begin());
    }

    FORR(i, N-2, 0) B_choice[i] += B_choice[i+1]; 

    REP(i, N) {
        int a = A[i];
        auto itr_b = upper_bound(B.begin(), B.end(), a);
        ans += B_choice[itr_b - B.begin()];
    }

    cout << ans << endl;

    return 0;
}