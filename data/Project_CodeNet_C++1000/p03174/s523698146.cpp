#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

const int N = 21;
const int M = 1e9+7;
int dp[N][1<<N];
bool g[N][N];
int n;

inline int lg2(const int &x) { return 31-__builtin_clz(x); }

int f(int id, int mask) {
    if (id == n) return 1;
    int &r = dp[id][mask];
    if (r != -1) return r;
    
    r = 0;
    for (int aux = mask; aux; aux &= aux-1) {
        int j = lg2(aux & -aux);
        if (g[id][j]) {
            int next = mask^(1<<j);
            r = (r + f(id+1, next)) % M;
        }
    }
    return r;
    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    forn(i, 0, n) {
        forn(j, 0, n) {
            cin >> g[i][j];
        }
    }
    
    memset(dp, -1, sizeof dp);
    cout << f(0, (1<<n)-1) << endl;
}
