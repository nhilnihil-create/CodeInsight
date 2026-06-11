#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<int>> vvint;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<int, vector<int>, greater<int>> spqint; //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;     //小さい順に取り出し
typedef priority_queue<int, vector<int>, less<int>> bpqint;    //大きい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;        //大きい順に取り出し

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
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
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}
//-----------------------------------------
vector<long long> factor_array(long long n){
    vector<long long> res ;
    for(long long i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i) ;
            if(i*i!=n){
                res.push_back(n/i) ;
            }
        }
    }
    sort(res.begin(),res.end()) ;
    return res ;
}

bool is_prime(long long n){
    if(n==2){
        return true ;
    }
    else if(n<2 || n%2==0){
        return false ;
    }
    else{
        long long i = 3 ;
        while(i*i<=n){
            if(n%i==0){
                return false ;
            }
            i += 2 ;
        }
        return true ;
    }
}

vector<pair<long long, long long>> prime_factorization(long long n){
    vector<pair<long long, long long>> res ;
    vector<long long> tmp = factor_array(n) ;
    for(long long i = 0; i<(long long)tmp.size(); i++){
        if(is_prime(tmp[i])){
            long long m = n ;
            long long cnt = 0 ;
            while(m%tmp[i]==0){
                m /= tmp[i] ;
                cnt++ ;
            }
            res.push_back(make_pair(tmp[i],cnt)) ;
        }
    }
    return res ;
}
//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::chrono::system_clock::time_point start,end;
    start = std::chrono::system_clock::now();
    ll n, m ;
    cin >> n >> m ;
    vll fa = factor_array(m) ;
    ll ans = 0 ;
    REP(i,SZ(fa)){
        if(n*fa[i]<=m){
            ans = fa[i] ;
        }
    }
    cout << ans <<endl;


    end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count();
    //std::cout << elapsed <<"ms"<< std::endl;

    

    return 0;
}

