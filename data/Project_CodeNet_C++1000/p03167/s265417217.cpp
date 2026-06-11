#include<bits/stdc++.h>

typedef long long int lli;
typedef long double lld;
typedef long long ll;
//Datatype
#define vi vector<int>
#define vlli vector<long long int>
#define vvi vector<vector<int>>
#define vvlli vector<vector<long long int>>
#define ppi pair<int, int>
#define rppi pair<int, pair<int, int>>
#define lppi pair<pair<int, int>, int>
#define vppi vector<pair<int, int>>
#define sppi stack<pair<int int>>
#define qppi queue<pair<int, int>>
//function
#define f first
#define s second
#define pb(x) push_back(x)
#define mkp(i, j) make_pair(i, j)
#define lmkp(i,j,k) make_pair(make_pair(i,j),k)
#define rmkp(i,j,k) make_pair(i,make_pair(j,k))
//loop
#define loop(i,n) for (i = 0; i < n; ++i)
#define loops(i,k,n) for (i = k; i <= n; ++i)
#define looprev(i,k,n) for (i = k; i >= n; --i)
//Const
#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
//Print
#define prd(n) printf("%d", n)
#define prl(n) printf("%lld", n)
#define prdn(n) printf("%d\n", n)
#define prln(n) printf("%lld\n", n)
#define prf(n) printf("%f", n)
//Scan
#define scd(n) scanf("%d", &n)
#define scd2(a, b) scanf("%d %d", &a, &b)
#define scd3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define scl(n) scanf("%lld", &n)
#define scl2(a, b) scanf("%lld %lld", &a, &b)
#define scl3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define scf(n) scanf("%f", &n)

using namespace std;
char grid[1001][1001];
lli g[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli i, j, k, N, M;
    cin>>N>>M;
    loop(i, N){
        loop(j, M){
            cin>>grid[i][j];
        }
    }
    loop(i, N){
        loop(j, M){
            if(i == 0 && j == 0) g[i][j] = 1;
            else if(grid[i][j] == '#') g[i][j] = 0;
            else if(i == 0 && j != 0) g[i][j] = g[i][j-1];
            else if(i != 0 && j == 0) g[i][j] = g[i-1][j];
            else g[i][j] = (g[i-1][j]+g[i][j-1])%MOD;
        }
    }
    /*loop(i, N){
        loop(j, M){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<g[N-1][M-1]<<endl;
  return 0;
}