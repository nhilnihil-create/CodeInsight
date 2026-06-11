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
int main(){
    int n;
    sci(n);
    vi cnt(4);
    rep(i,1,n){
        int x;
        sci(x);
        ++cnt[x];
    }
    double ev[n+1][n+1][n+1];
    for(int c=0;c<=cnt[3];++c){
        for(int b=0;b<=cnt[2]+cnt[3];++b){
            for(int a=0;a<=cnt[1]+cnt[2]+cnt[3];a++){
                if(a+b+c == 0 || a+b+c > n) continue;
                double p_waste = 1.0*n/(a+b+c);
                double p_a = 1.0*a/(a+b+c);
                double p_b = 1.0*b/(a+b+c);
                double p_c = 1.0*c/(a+b+c);
                ev[a][b][c] = p_waste;
                if(a) ev[a][b][c] += p_a*ev[a-1][b][c];
                if(b) ev[a][b][c] += p_b*ev[a+1][b-1][c];
                if(c) ev[a][b][c] += p_c*ev[a][b+1][c-1];
            }
        }
    }
    cout.precision(10);
    cout << fixed << ev[cnt[1]][cnt[2]][cnt[3]] << endl;
}