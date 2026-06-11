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
int dp[110000][3];
int vacation(int N, vector<int> A, vector<int> B, vector<int> C){
    int i, j, k, res = 0;
    loop(i, N){
        loop(j, 3){
            if(i == 0){
                if(j == 0) dp[i][j] = A[i];
                else if(j == 1) dp[i][j] = B[i];
                else dp[i][j] = C[i];
            }
            else{
                loop(k, 3){
                    if(j == k) continue;
                    if(j == 0) dp[i][j] = max(dp[i][j], dp[i-1][k]+A[i]);
                    else if(j == 1) dp[i][j] = max(dp[i][j], dp[i-1][k]+B[i]);
                    else dp[i][j] = max(dp[i][j], dp[i-1][k]+C[i]);

                }
            }
        }
    }
    res = max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2]));
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli i, j, N;
    cin>>N;
    vector<int> a(N, 0), b(N, 0), c(N, 0);
    loop(i, N){
        cin>>a[i]>>b[i]>>c[i];
    }
    int res = vacation(N, a, b, c);
    cout<<res<<endl;
  return 0;
}