#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long int
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF 100000000000
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
const int mod = 1000000007;
const int N = 2e5+5, M = N;
//=========================================

const int MAXN = 302;
double dp[MAXN][MAXN][MAXN];
int n, vis[MAXN][MAXN][MAXN];

double solve(int x, int y, int z){
    if(vis[x][y][z]) return dp[x][y][z];
    // mark the state visited
    vis[x][y][z] = 1;

    if(x == 0 && y == 0 && z == 0) return dp[x][y][z] = 0;

    int soma = x + y + z;
    double convert = (double)soma;
    double rem = (n - soma) / convert;

    if(x != 0) rem += x * ((solve(x - 1, y, z) + 1) / convert);
    if(y != 0) rem += y * ((solve(x + 1, y - 1, z) + 1) / convert);
    if(z != 0) rem += z * ((solve(x, y + 1, z - 1) + 1) / convert);

    return dp[x][y][z] = rem;
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int a[4] = {0, 0, 0, 0};
    cin >> n;

    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        a[x]++;
    }

    double answer = solve(a[1], a[2], a[3]);
    cout << fixed << setprecision(9) << answer << "\n";

    return 0;
}
