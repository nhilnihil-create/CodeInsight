#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for(int i=(l);i<(r);i++)
#define forb(i,r,l) for(int i=(r);i>(l);i--)
#define log2i(x) 32 - __builtin_clz((x)) - 1
#define log2ll(x) 64 - __builtin_clzll((x)) - 1
#define Pi acos(-1.0)
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int N = 18;
int n;
int a[N][N];
ll dp[1<<N]={0};

int main() {
#ifndef ONLINE_JUDGE
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
#endif
    fastIO;
    cin >> n;
    forw(i,0,n) {
        forw(j,0,n) cin >> a[i][j];
    }
    forw(i,1,1<<n) {
        ll res=0;
        forw(j,0,n) {
            forw(k,0,j) {
                if(((i>>j)&1)&&((i>>k)&1)) res+=a[j][k];
            }
        }
        for(int j=i;j;j=((j-1)&i)) res=max(res,dp[j]+dp[i-j]);
        dp[i]=res;
    }
    cout << dp[(1<<n)-1];
    return 0;
}
