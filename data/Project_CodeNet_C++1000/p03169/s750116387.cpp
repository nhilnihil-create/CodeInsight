#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define XX              first
#define YY              second
#define PB              push_back
#define MP              make_pair

#define NEWLINE         cerr << "\n";
#define HOISE           cerr << "hoise " << __LINE__ << "\n"
#define PAUSE           system("pause")
#define DEBUG(x)        cerr << #x << " = " << x << "\n"
#define FASTIO          ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long long ll;
typedef pair<int, int > pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 23;
const ll INFL = 2e18 + 23;

const int MAX = 300 + 2;

int N;
double dp[MAX][MAX][MAX];
bool vis[MAX][MAX][MAX];

double re(int a, int b, int c)
{
    int n = a+b+c;
    if(n == 0) return 0;
    if(vis[a][b][c]) return dp[a][b][c];
    double &ret = dp[a][b][c];
    vis[a][b][c] = true;

    ret = 0;
    if(a) ret += (re(a-1, b, c) + 1)  *a;
    if(b) ret += (re(a+1, b-1, c) + 1)*b;
    if(c) ret += (re(a, b+1, c-1) + 1)*c;
    ret = (ret+N-n)/n;
    return ret;
}

int32_t main()
{
    FASTIO;

    int a = 0, b = 0, c = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x == 1) a++;
        else if(x == 2) b++;
        else c++;
    }

    cout << fixed << setprecision(12) << re(a, b, c);

    return 0;
}