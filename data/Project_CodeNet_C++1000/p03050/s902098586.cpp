#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Pld = pair<ld, ld>;
using Vec = vector<ll>;
using VecP = vector<P>;
using VecB = vector<bool>;
using VecC = vector<char>;
using VecD = vector<ld>;
using VecS = vector<string>;
using Graph = vector<VecP>;
#define REP(i, m, n) for(ll (i) = (m); (i) < (n); ++(i))
#define REPR(i, m, n) for(ll (i) = (m); (i) > (n); --(i))
#define rep(i, n) REP(i, 0, n)
#define R cin>>
#define i64 unsigned long long
#define repr(i, n) REPR(i, n, 0)
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define in(a) insert(a)
#define P(p) cout<<(p)<<endl;
#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define SORT(a) sort((a).begin(), (a).end())
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long int> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
void sonic(){ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);}
void setp(const ll n){cout << fixed << setprecision(n);}
const ll INF = 1e9+1;
const ll LINF = 1e18+1;
const ll mod = 1e9+7;
//const ll MOD = 998244353;
const ld PI = acos(-1);
const ld EPS = 1e-11;
template<typename T> void co(T e){cout << e << "\n";}
template<typename T> void co(const vector<T>& v){for(const auto& e : v)
    { cout << e << " "; } cout << "\n";}
ll gcd(ll a, ll b) {
    if (a < b)swap(a, b);
    if (b == 0) return a;
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return a * b / g;
}
bool prime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n%i == 0)return false;
    }
    return n != 1;
}


int pow(int x, int y, int mod){
    int ret=1;
    for(;y;y>>=1,x=1ll*x*x%mod){
        if(y&1) ret=1ll*ret*x%mod;
    }
    return ret;
}
void kill()
{
    cout << "No" << endl;
    exit(0);
}

template <class T>bool chmax(T &a, const T &b){if (a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;} return 0;}





int main(){
    sonic();
    ll n, ans=0;
    R n;
    Vec div;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0)div.push_back(i);
        if(i*i!=n)div.push_back(n/i);
    }

    for(auto it:div){
        if(it==1)continue;
        if(n%(it-1)==n/(it-1))ans+=it-1;
    }
    co(ans);
}
