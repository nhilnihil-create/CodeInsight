#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define No              cout<<"No\n";
#define Yes             cout<<"Yes\n";
#define no              cout<<"NO\n";
#define yes             cout<<"YES\n";
#define MOD             (int)998244353
#define int             long long
#define ll              long long
#define pii             pair<int, int>
#define fi               first
#define se              second
#define sf(a)           scanf("%lld", &a)
#define pf(a)           printf("%lld ", a)
#define Case(a)         printf("Case %lld: ", a)
#define FASTIO          ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb              emplace_back
#define mp              make_pair
#define mem(arr)        memset(arr, 0, sizeof(arr))
#define mem1(arr)       memset(arr, -1, sizeof(arr))
#define all(a)          a.begin(),a.end()
#define for0(i, n)      for (int i = 0; i < n; i++)
#define for1(i, n)      for (int i = 1; i <= n; i++)
#define loop(i,a,b)     for (int i = a; i < b; i++)
#define rloop(i,a,b)    for (int i = a ; i>=b;i--)
#define rr              return 0
#define prec(n)         fixed<<setprecision(n)
#define maxpq           priority_queue<int>
#define minpq           priority_queue<int, vector<int>, greater<int> >
#define inf             (int)(1e18)
#define vi              vector<int>
#define endl            "\n"
#define vii             vector<pii>
#define sz(s)           s.size()
#define bits(n)         __builtin_popcount(n)
#define MX              500005
#define svMX            200005

int gcd(int a, int b)   {return __gcd(a,b);}
void pr(int x)          {cout << x;}
void prl(int x)         {cout << x << endl;}

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

int p[svMX+9];
vector<ll>prime;

void sieve()
{
    int sq = sqrt(svMX);

    for(int i=3;i<=sq;i+=2){
        if(p[i] == 0){
            for(int j=i*i;j<=svMX;j+=2*i){
                p[j] = 1;
            }
        }
    }

    prime.pb(2);
    for(int i=3;i<=svMX;i+=2){
        if(p[i] == 0){
            prime.pb(i);
//            cout<<i<<" ";
        }
    }
}

const double eps = 1e-9;
const double pi = acos(-1);

int dx[5] = {+1, +0, -1, -0};
int dy[5] = {+0, +1, -0, -1};
int XX[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int YY[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool Equal(double x, double y)
{
    return fabs(x-y)<eps; ///x==y
}

bool Greater(double x, double y)
{
    return x-eps>y; ///x>y
}

bool Lesser(double x, double y)
{
    return x+eps<y; ///x<y
}

struct point
{
    double x, y, ang;
};


//////          https://www.youtube.com/watch?v=9uaXG62Y8Uw
///           Fenwick Tree
#define ftmx            1000006

int ft[ftmx];
void ftupdate(int i, int add)
{
    while(i>0 && i<ftmx){
        ft[i] += add;
        i += (i&(-i));
    }
}

int ftsum(int i)
{
    int s = 0;
    while(i>0){
        s += ft[i];
        i -= (i&(-i));
    }
    return s;
}
int ftfind(int k)
{
    int curr=0, ans =0, prevsum=0;
    for(int i= 20; i>= 0;i--){
        if(curr+(1<<i)<ftmx && ft[curr+(1<<i)]+prevsum < k){
            curr += 1<<i;
            ans = curr;
            prevsum += ft[curr];
        }
    }

    return ans+1;
}


////       https://www.youtube.com/watch?v=V5-7GzOfADQ
////       https://www.youtube.com/watch?v=sMARZCTPyNI
///..............KMP...............
vector<int> constructTempArray(string pattern)
{
    vector<int> lps(pattern.length());
    int index = 0;
    for (int i = 1; i < (int) pattern.length(); ) {
        if (pattern[i] == pattern[index]) lps[i] = index + 1, ++index, ++i;
        else {
            if (index != 0) index = lps[index - 1];
            else lps[i] = index, ++i;
        }
    }
    return lps;
}

void KMPMultipleTimes (string text, string pattern)
{
    bool found = false;
    vector<int> lps = constructTempArray(pattern);
    int j = 0, i = 0;

    // i --> text, j --> pattern
    while (i < (int) text.length()) {
        if (text[i] == pattern[j]) ++i, ++j;
        else {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }

        if (j == (int) pattern.length()) {
            cout << "found match at : " << (i - pattern.length()) << endl;
            j = lps[j-1];
            found = true;
        }
    }

    if (!found) cout << "not found" << endl;
}

///...................Trie......................///
struct trinode {
    bool endmark;
    trinode* next[26 + 1];
    trinode()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;
void triinsert(char* str, int len)
{
    trinode* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new trinode();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
bool trisearch(char* str, int len)
{
    trinode* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}
void tridel(trinode* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            tridel(cur->next[i]);

    delete (cur);
}



///Template Ends Here////////////////////////////
const int N = 100009;
vi g[N];
map<int, map<int,int> >val;
int col[N], vis[N];

void dfs(int s)
{
    vis[s] = 1;

    for(int x:g[s]){
        if(vis[x] == 0){
            if(val[s][x]%2){
                col[x] = 1-col[s];
            }
            else
                col[x] = col[s];

            dfs(x);
        }
    }
}
signed main()
{
//    root = new trinode();


    FASTIO

    int n, x, y, w;
    cin>>n;

    for1(i, n-1){
        cin>>x>>y>>w;
        g[x].pb(y);
        g[y].pb(x);

        val[x][y] = val[y][x] = w;
    }

    mem1(col);
    col[1] = 0;
    dfs(1);


    for1(i, n){
        cout<<col[i]<<" ";
    }
//    tridel(root);
}



