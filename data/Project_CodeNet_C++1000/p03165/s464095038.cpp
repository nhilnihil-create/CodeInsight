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

lli dp[3001][3001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli i, j, k;
    loop(i, 3001){
        loop(j, 3001){
            dp[i][j] = 0;
        }
    }
    string s, t, res = "";
    cin>>s>>t;
    lli M = s.size(), N = t.size();
    loop(i, M+1){
        loop(j, N+1){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    /*loop(i, M+1){
        loop(j, N+1){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    i = M, j = N;
    while(i > 0 && j > 0){
        if(dp[i-1][j-1]+1 == dp[i][j] && dp[i-1][j]+1 == dp[i][j] && dp[i][j-1]+1 == dp[i][j]){
            i--;
            j--;
            res = s[i]+res;
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }
    cout<<res<<endl;
  return 0;
}