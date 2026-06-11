#include<bits/stdc++.h>

using namespace std;

#define ok1 printf("ok1\n");
#define ok2 printf("ok2\n");
#define M 1000000000000000000LL
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=(s);i<(n);i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define REPR(i,s,n) for(int i=(s);i>=(n);i--)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define pf push_front
#define MIN(a,b) a=min((a),(b))
#define MAX(a,b) a=max((a),(b))
#define SIZE(v) (int)v.size()
#define Eunique(v) v.erace(unique(all(v)),v.end())
#define pvec(v)　rep(i,v.size()){cout << v[i] << " ";}
#define INF 0x3f3f3f3f
#define mset(m,v) memset(m,v,sezeof(m))
#define mod (int)(1e9 +7);

const double pi = acos(-1.0);

typedef vector<int> vi;
typedef string ss;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef deque<ll> dll;
typedef pair<ll,ll> P;
ll dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b; // Be careful not to overflow
}

vll binary_convert(ll n){
    vll s;
    ll size = 0;

    while(n / (ll)(pow(2,size)) > 0)size++;
    rep(i,size + 1){
        s.pb(n / (ll)(pow(2,i)));
        n %= (ll)(pow(2,i));
    }

    return s;
}

int main()
{
    ll n;
    cin >> n;
    string a,b,c;
    cin >> a >> b >> c;

    ll ans = 0;
    rep(i,n){
        if(a[i] != b[i] && a[i] != c[i] && b[i] != c[i])ans += 2;
        else if((a[i] != b[i] && a[i] == c[i]) || (a[i] != c[i] && a[i] == b[i]) || (b[i] == c[i] && b[i] != a[i]))ans++;
    }

    cout << ans << endl;
    return 0;
}