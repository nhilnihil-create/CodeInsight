#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define INF 1e17
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define PI 3.1415926535897932384626433832795
#define endl "\n"
#define f first
#define se second
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
long long MOD = 998244353;
pair<int,int> dx[4] = {{1,0},{-1,0},{0,1},{0,-1}};
char symbol[4] = {'U','D','L','R'};
char symbol2[4] = {'D','U','R','L'};
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct chash {int operator()(int x) const { return x ^ RANDOM; }};
string toString(long long x){stringstream ss;ss << x;string str = ss.str();return str;}
long long fastpow(long long x,long long k){if(!k)return 1;if(k & 1)return ((x * fastpow(x,k-1) % MOD) % MOD) % MOD;
long long ans = fastpow(x,k/2);ans %= MOD;ans *= ans;ans %= MOD;return ans;}
long long sumF(long long x){int s = 0;while(x)s += x%10,x /= 10;return s;}
bool isS(char c){return (c >= 'a' && c <= 'z');}
bool isB(char c){return (c >= 'A' && c <= 'Z');}
bool isD(char c){return (c >= '0' && c <= '9');}
bool isSqrt(long long x){ long long f = sqrt((long double)x + 0.5); return f*f == x;}
bool isCubic(long long x) {long long f = cbrt((long double)x + 0.5); return f*f*f == x;}
long long lcm(long long a,long long b){return a * (b / __gcd(a,b));}
vector<long long> divVec(long long x){vector<long long> tmp;for(long long i = 1;1LL*i*i <= x;i++){if(x % i == 0){tmp.push_back(i);if(x / i != i)
tmp.push_back(x / i);}sort(tmp.begin(),tmp.end());}return tmp;}
int random_int(int l,int r){return uniform_int_distribution<int>(l,r)(rng);}
int primeFactorsCnt(long long n){int ret = 0;if(n % 2 == 0)ret++;while (n % 2 == 0)n = n/2;for (int i = 3; i*i <= n; i = i + 2){if(n % i == 0)ret++;while (n % i == 0)
n = n/i;}if (n > 2)ret++;return ret;}
long long mulmod(long long a,long long b){return (a%MOD  * b%MOD) % MOD;}
long long minusmod(long long a,long long b){return ((((a % MOD) - (b % MOD)) % MOD) + MOD) % MOD;}
long long plusmod(long long a,long long b){return ((a % MOD) + (b % MOD)) % MOD;}
long long divmod(long long a,long long b) {return mulmod(a,fastpow(b,MOD-2));}
vector<int> primeDivisors(int x){vector<int> ans;if(x % 2 == 0)ans.push_back(2);while(x %2 == 0)x /= 2;for(int i = 3;i*i <= x;i += 2)
{if(x % i == 0){ans.push_back(i);while(x % i == 0)x /= i;}}if(x > 1)ans.push_back(x);return ans;}
/*const int N = 1e5+5;
bool isCentroid[N];
int subtreeSize[N];
int depth[N];
int inTime[N];
int outTime[N];
int LCA[N][20];
static int curTime;
vector<pair<int,int> >  edgeList[N];
int parentCentroid[N];
int getSubtreeSize(int node,int parent = 0)
{
    subtreeSize[node] = 1;
    for(auto const &it : edgeList[node])
    {
        if(parent == it.first || isCentroid[it.first])
            continue;
        getSubtreeSize(it.first,node);
        subtreeSize[node] += subtreeSize[it.first];
    }
    return subtreeSize[node];
}
int findCentroid(int node,int treeSize,int parent = 0)
{
    int nextNode = -1;
    for(auto const& it : edgeList[node])
    {
        if(parent == it.first || isCentroid[it.first])
            continue;
        if(subtreeSize[it.first] > treeSize/2)
            nextNode = it.first;
    }
    if(nextNode == -1)
        return node;
    return findCentroid(nextNode,treeSize,node);
}
int decomposeTree(int node)
{
    int centroid = findCentroid(node,getSubtreeSize(node));
    isCentroid[centroid] = true;
    for(auto const &it : edgeList[centroid])
    {
        if(!isCentroid[it.first])
        {
            int nextCentroid = decomposeTree(it.first);
            parentCentroid[nextCentroid] = centroid;
        }
    }
    return centroid;
}
void DFS(int node,int curDepth = 0,int parent = 0)
{
    LCA[node][0] = parent;
    for(int i = 1;i < 20;i++)
        LCA[node][i] = LCA[LCA[node][i-1]][i-1];
    inTime[node] = curTime;
    depth[node] = curDepth;
    curTime++;
    for(auto const &it : edgeList[node])
    {
        if(parent == it.first)
            continue;
        DFS(it.first,curDepth + it.second,node);
    }
    outTime[node] = curTime;
}
bool isAncestor(int u,int v)
{
    return (inTime[u] <= inTime[v] && outTime[u] >= outTime[v]);
}
int getLCA(int u,int v)
{
    if(depth[u] > depth[v]) swap(u,v);
    if(isAncestor(u,v)) return u;
    for(int i = 19;i >= 0;i--)
    {
        if(!isAncestor(LCA[u][i],v) && LCA[u][i] != 0)
            u = LCA[u][i];
    }
    return LCA[u][0];
}
int getDis(int u,int v)
{
    int curLCA = getLCA(u,v);
    return depth[u] - depth[curLCA] + depth[v] - depth[curLCA];
}*/
pair<int,pair<int,int> > myArr[1005];
int dp[1005][10005];
int n;
bool myCmp(pair<int,pair<int,int> >& a,pair<int,pair<int,int> >& b)
{
    return a.first + a.second.first < b.first + b.second.first;
}
int solve(int idx,int totalWeight)
{
    if(idx == n || totalWeight > 10000)
        return 0;
    if(dp[idx][totalWeight] != -1)
        return dp[idx][totalWeight];
    int C = solve(idx + 1,totalWeight);
    if(myArr[idx].second.first >= totalWeight)
        C = max(C,solve(idx + 1,totalWeight + myArr[idx].first) + myArr[idx].second.second);
    return dp[idx][totalWeight] = C;
}
int32_t main()
{
    IO;
    //freopen("robots.in","r",stdin);
    int _ = 1;
    //cin >> _;
    int curTest = 1;
    while(_--)
    {
        memset(dp,-1,sizeof dp);
        cin >> n;
        for(int i = 0;i < n;i++)
            cin >> myArr[i].first >> myArr[i].second.first >> myArr[i].second.second;
        sort(myArr,myArr + n,myCmp);
        cout << solve(0,0);
    }
    return 0;
}
