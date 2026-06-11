#include<bits/stdc++.h>

using namespace std;

//Shortcut
#define long long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define X first
#define Y second
#define sz size
#define ft(i , a , b) for (long i = (long)a ; i <= (long)b ; i++)
#define fd(i , a , b) for (long i = (long)a ; i >= (long)b ; i--)
#define lt(i , a , b , c) for (long i = (long)a ; i <= (long)b ; i += (long)c)
#define ld(i , a , b , c) for (long i = (long)a ; i >= (long)b ; i -= (long)c)
#define pll pair <long , long>
#define pls pair <long , string>
#define vtl vector <long>
#define vts vector <string>
#define vtp vector <pll>
#define dql deque <long>
#define mll map <long , long>
#define prio priority_queue<pll , vector<pll > , greater<pll> >
#define pushpq(a , b) push({(long) a , (long) b})

//Variable
const long mxN = 1e3 + 5;
const long base = 311;
const long oo = 1e15;
const long MOD = 1e9 + 7;
const long d4i[4] = {-1 , 0 , 1 , 0} , d4j[4] = {0 , 1 , 0 , -1};
const long d8i[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1} , d8j[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

int TestCase;
int n , m , answer; 
int dp[mxN][mxN];
bool mark[mxN][mxN];
char a[mxN][mxN];

void Solve() {
    cin >> n >> m;
    ft(i , 1 , n) ft(j , 1 , m) cin >> a[i][j];
    dp[1][1] = 1;
    ft(i , 1 , n) {
        ft(j , 1 , m) {
            if (a[i][j] == '#') continue;
            if (i == 1 && j == 1) continue;
            dp[i][j] = (dp[i - 1][j] % MOD + dp[i][j - 1] % MOD) % MOD;
        }
    }
    cout << dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //cin >> TestCase;
    TestCase = 1;
    while(TestCase--)
        Solve();
    return 0;
}