#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;
typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;
typedef pair<string , string>       pss;
#define pb(x)                       push_back(x)
#define ts(x)                       to_string(x)
#define ti(x)                       stoi(x)
#define all(x)                      (x).begin(),(x).end()
#define F                           first
#define S                           second
#define Mp                          make_pair
#define tab                         '\t'
#define sep                         ' '
#define mine(v)                     *min_element(all(v))
#define maxe(v)                     *max_element(all(v))
#define error(x)                    cerr << #x << " = " << x << endl
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io                     freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define endl                        "\n"
inline ll input(){ll n; cin >> n ; return n;}
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const ll INF = 8e18;

ll n,q,ans;
ll arr[MAXN];
vector<pll> que;

bool check1(ll x){
    ll pos = x;
    for(int i = 0;i < que.size();i++){
        ll ch = que[i].F;
        ll act = que[i].S;
        if(arr[pos] == ch)
            pos += act;
        if(pos == 0)
            return true;
    }
    return false;
}

bool check2(ll x){
    ll pos = n - x + 1;
    for(int i = 0;i < que.size();i++){
        ll ch = que[i].F;
        ll act = que[i].S;
        if(arr[pos] == ch)
            pos += act;
        if(pos == n + 1)
            return true;
    }
    return false;
}

int main()
{
    fast_io;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 1;i <= n;i++){
        arr[i] = s[i - 1] - 'A';
    }
    char c1,c2;
    ll tmp,act;
    for(int i = 1;i <= q;i++){
        cin >> c1 >>  c2;
        tmp =(ll)c1 - 'A';
        if(c2 == 'L')
            act = -1;
        else
            act = 1;
        que.push_back({tmp,act});
    }
    ll l,mid,r;
    l = 0;
    r = n + 2;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if(check1(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    ans += l;
    l = 0;
    r = n + 2;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if(check2(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    ans += l;
    ans = n - ans;
    cout << ans << endl;
}

