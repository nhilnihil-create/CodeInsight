#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;     //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;        //大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define TS to_string
#define BS binary_search
#define LB lower_bound
#define UB upper_bound
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


int INF = 1e9;
int NIL = -1;
ll MOD = 1000000007;
ll LINF = 1e18;
double EPS = 1e-9;
double PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}
//-----------------------------------------

//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll d, g;
    cin >> d >> g;
    vll p(d);
    vll c(d);
    REP(i,d){
        cin >> p[i] >> c[i];
    }

    ll ans = LINF;

    vll hog;
    for(ll i=d-1;i>=0;i--){
        for(ll j=0;j<p[i]-1;j++){
            hog.PB(100*(i+1));
        }
    }

    ll m = SZ(hog);

    for (int bitt = 0; bitt < (1 << 11); bitt++) {
        bitset<11> bits(bitt); 
        ll tmp = 0;
        ll cnt = 0;
        
        for(ll i=0;i<d;i++){
            if(bits[i]==1){
                cnt += p[i];
                tmp += 100*(i+1)*p[i] + c[i];
            }
        }

        ll k = 0;
        while(tmp<g){
            if(k==m){
                break;
            }
            if(bits[hog[k]/100-1]==0){
                tmp += hog[k];
                cnt++;
            }
            k++;
        }
        if(k==m && tmp<g){
            continue;
        }

        ans = min(ans,cnt) ;

    }

    cout << ans <<endl;



    
    return 0;
}

