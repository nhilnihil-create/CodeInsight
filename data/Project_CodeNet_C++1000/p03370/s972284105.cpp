#include <bits/stdc++.h>
 
using namespace std;

// traduções

// even -> par
// odd -> impar

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-12
const double PI = acos(-1.0);

#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define FILL(a,v) memset(a, v, sizeof a)

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
    
    int N, X;

    scanf(" %d %d", &N, &X);

    vi m(N);

    int menor = INF;

    REP(i, 0, N) {
        scanf(" %d", &m[i]);
        X -= m[i];
        menor = min(menor, m[i]);
    }

    int total = N + (X / menor);   

    printf("%d\n", total);

    return 0;
}
