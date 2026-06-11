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
const int N = 1e5 + 3;
lli n, mem[N][2];
li adj[N];

lli dfs(int s, int c, int p){
    if(mem[s][c] != -1)
    return mem[s][c];


    int ff = 0;
    lli ans = 1;

    for(auto x:adj[s]){
        if(x != p){
            ff = 1;

            if(c == 0){
                ans *= (dfs(x, 0, s) + dfs(x, 1, s));
                ans %= md;
            } else {
                ans *= dfs(x, 0, s);
                ans %= md;
            }
        }
    }


    if(!ff){
        return 1;
    }

    return mem[s][c] = ans;
}


void solve(){
    cin>>n;

    fill(mem, -1);

    fori(i, 1, n-1){
        int x, y; cin>>x>>y;

        adj[x].pb(y);
        adj[y].pb(x);
    }    

    lli ans = 0;
    ans += dfs(1, 0, -1);
    ans %= md;

    ans += dfs(1, 1, -1);
    ans %= md;

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