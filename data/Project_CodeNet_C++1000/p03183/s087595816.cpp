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
const int MAX = 2e4;
class Block{
public:
    int w,s,v;
    Block(int a,int b,int c){
        w = a;
        s = b;
        v = c;
    }
};
bool com(Block a,Block b){
    return a.s + a.w < b.s + b.w;
}
int main(){
    int n;
    sci(n);
    vector<Block> in;
    rep(i,1,n){
        int w,s,v;
        sciii(w,s,v);
        in.pb(Block(w,s,v));
    }
    vll dp(MAX+1,0);
    sort(all(in),com);
    for(Block block:in){
        for(int w = min(block.s+block.w,MAX);w>=block.w;--w){
            dp[w] = max(dp[w],dp[w-block.w] + block.v);
        }
    }
    ll ans = 0;
    for(ll i:dp)
        ans = max(ans,i);
    cout << ans << endl;
}
