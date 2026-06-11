                                                                   //author rhythmicankur
                                                                  //god_is_almighty
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#define f 		first
#define s 		second
#define int     long long
#define ll      int
#define ld 		long double
#define pb 		push_back
#define eb 		emplace_back
#define mk 		make_pair
#define vi 		vector<int>
#define pii 		pair<int,int>
#define pip             pair<int,pii>
#define vpi 		vector<pii>
#define sbcount(x) __builtin_popcountll(x)
#define REP(i,n) for (int i = 1; i <= n; i++)
#define trav(a, x)      for(auto& a : x)
#define all(x)          x.begin(), x.end()
#define fill(a,val)	memset(a,val,sizeof(a))
#define 	PI acos(-1)
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define M1 	998244353
#define M2 	1000000007
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); } 
#define test4(x,y,z,a) 		    cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<"  |  "<<#a<<": "<<a<<endl;
#define test1(x)                cerr<<#x<<": "<<x<<endl
#define test2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define test3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
ll power(ll a,ll b,ll m=M2){ll answer=1;while(b){if(b&1)answer=(answer*a)%m;b/=2;a=(a*a)%m;}return answer;}
using namespace std;
void ctrl(){cout<<"Control"<<endl;}
int make_num(string p){stringstream geek(p); int x = 0; geek >> x;return x;}
string make_str(int x){ostringstream str1; str1 << x; string geek = str1.str(); return geek;}
const int N=1e5+5;
int dp[N][2];
vi v[N];
void dfs(int x,int par)
{
    dp[x][0]=dp[x][1]=1;
    int val=1,val2=1;
    for(auto it:v[x])
    {
        
        if(it!=par)
        {
            dfs(it,x);
            val = (val*dp[it][0])%M2;
            val2 = (val2*(dp[it][0] + dp[it][1]))%M2;
        }
    }
    dp[x][0] = val2;
    dp[x][1] = val;
} 
signed main()
{	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin.exceptions(cin.failbit);
	int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(0,0);
    cout<<(dp[0][1]+dp[0][0])%M2;

return 0;
}