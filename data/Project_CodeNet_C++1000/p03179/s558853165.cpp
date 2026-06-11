#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<char,int> pci;
typedef vector<pair<int,int>> vpii;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
#define sci(a) scanf("%d",&a)
#define scii(a,b) scanf("%d %d",&a,&b)
#define sciii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sciiii(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define scl(a) scanf("%lld",&a)
#define scll(a,b) scanf("%lld %lld",&a,&b)
#define sclll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c
#define scllll(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define print(a) printf("%d ",a)
#define println(a) printf("%d\n",a)
#define ln printf("\n")
#define pb(a) push_back(a)
#define m_p(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define rrep(i,e,s) for(int i=e;i>=s;i--)
#define repv(i,m) for(auto i = m.begin();i != m.end();i++)
#define FileIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const long long INF = 4000000000000000000LL;
/************************************* Chocolate *************************************/
const int mod = 1e9+7;
int main(){
    int n;
    string s;
    sci(n);
    cin >> s;
    s = " "+ s;
    vvi dp(n+1,vi(n+1,0)); //dp[i][j] = #of permutations of size 'i' with first i numbers where last element is 'j'.
    dp[1][1] = 1;
    vi prev(n+1,0);
    prev[1] = 1;
    rep(i,1,n-1){
        vi now(n+1,0);
        rep(j,1,i+1){
            if(s[i] == '>')
                dp[i+1][j] = (prev[i] - prev[j-1] + mod)%mod;
            else
                dp[i+1][j] = prev[j-1];
            now[j] = (now[j-1] + dp[i+1][j])%mod;
        }
        prev = now;
    }
    cout << prev[n] << endl;
}