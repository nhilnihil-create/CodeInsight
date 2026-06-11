#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-12

#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

// bitmask operations
#define SETBIT(S, j) S |= (1 << j)
#define CLEARBIT(S, j) S &= ~(1 << j)
#define ISSET(S, j) S & (1 << j)
#define FLIPBIT(S, j) S ^= (1 << j)
#define LSBIT(S) (S & (-S))

// debug
#define DEBUGSTR(S) cout << "(" << S << ")\n";

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    scanf(" %d", &N);

    printf("%d\n", N/3);

    return 0;
}