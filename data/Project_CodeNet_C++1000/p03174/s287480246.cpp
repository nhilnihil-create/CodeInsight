#include <bits/stdc++.h>
using namespace std;

#define fori(i,a,b)    for(int i=a;i<=b;i++)
#define ford(i,a,b)   for(int i=a;i>=b;i--)
#define all(a)        a.begin(), a.end()
#define in(c,x)       ((c).find(x) != (c).end())
#define isp(c,x)      (find(all(c),x) != (c).end())
#define pb             push_back
#define ppb            pop_back
#define sz(x)          (int)x.size()
#define fill(a,v)      memset(a, v, sizeof a)
#define fs first
#define sc second
#define ub upper_bound
#define lb lower_bound
#define en '\n'

typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef pair< int, int > pii;
typedef pair< lli, lli > plli;
typedef list<int> li;
typedef map<int, int> mi;
typedef map<lli, lli> mlli;
lli gcd(lli a,lli b){return (!b)?a:gcd(b,a%b);}
int t = 1; int ti;


lli md = 1e9 + 7;
const int M = (1<<21) + 5;
lli dp[M][22], n, a[22][22];


void solve(){
    cin>>n;

    fori(i, 0, n-1){
        fori(j, 0, n-1)
        cin>>a[i][j];
    }

    fori(i, 0, n-1)
    dp[(1<<i)][0] = a[i][0];

    fori(i, 1, n-1){
        fori(p, 0, (1<<21)-1){
            if(__builtin_popcount(p) == i){
                fori(j,0, n-1){
                    if((p&(1<<j)) == 0 && a[j][i]){
                        dp[p^(1<<j)][i] += dp[p][i-1];
                        dp[p^(1<<j)][i] %= md;
                    }
                }
            }
        }
    }

    lli ans = 0;

    fori(p, 0, (1<<21)-1){
        ans += dp[p][n-1];
        ans %= md;
    }

    cout<<ans;
}
//THINK OF SPECIAL CASES, ARRAY LIMITS, LLI vs INT, 1LL

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cin>>t;

    // for(ti= 1; ti <= t; ti++)
    solve();

//    cout<<"\nTHINK OF SPECIAL CASES, ARRAY LIMITS, LLI vs INT, 1LL";
}