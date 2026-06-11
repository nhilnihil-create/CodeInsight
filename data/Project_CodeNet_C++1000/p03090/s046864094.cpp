#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define TS to_string
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


ll INF = 1e9;
ll NIL = -1;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
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

    ll n;
    cin >> n;
    vvll edge(n,vll(n,0));
    REP(i,n){
        REP(j,n){
            if(i!=j){
                edge[i][j] = 1;
            }
            else{
                edge[i][j] = 0;
            }
        }
    }

    if(n%2==0){
        REP(i,n){
            edge[i][n-1-i] = 0;
        }
    }
    else{
        REP(i,n-1){
            edge[i][n-2-i] = 0;
        }
    }
    ll m = 0;
    REP(i,n-1){
        FOR(j,i+1,n){
            if(edge[i][j]==1){
                m++;
            }
        }
    }
    cout << m <<endl;
    REP(i,n-1){
        FOR(j,i+1,n){
            if(edge[i][j]==1){
                cout << (i+1) <<" " << (j+1) <<endl;
            }
        }
    }



    
    return 0;
}