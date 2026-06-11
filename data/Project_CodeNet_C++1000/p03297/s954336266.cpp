#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

int T;
ll A, B, C, D;

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    FOR(i,0,T-1){
        cin >> A >> B >> C >> D;

        if (A < B || D < B) cout << "No" << '\n';
        else {
            ll x = __gcd(B,D);
            ll y = C-B+1 + A%x - ((C-B+1)%x + x)%x;
            if (y < C-B+1) y += x;
            cout << (y >= 0 ? "Yes" : "No") << '\n';
        }
    }
}

