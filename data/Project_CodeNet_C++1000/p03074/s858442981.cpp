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

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
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

//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::chrono::system_clock::time_point start,end;
    start = std::chrono::system_clock::now();

    ll n, k ;
    cin >> n >> k ;
    string s ;
    cin >> s ;
    bool f0, f1 ;
    f0 = f1 = true ;
    REP(i,n){
        if(s[i]=='0'){
            f0 = false ;
        }
        else{
            f1 = false ;
        }
    }
    if(f0 || f1){
        if(k!=0){
            cout << n <<endl;
        }
        else{
            if(f0){
                cout << 0 <<endl;
            }
            else{
                cout << n <<endl;
            }
        }
        return 0 ;
    }
    vll num1 ;
    vll num0 ;
    ll cnt = 0 ;
    if(s[0]=='0'){
        num1.PB(0) ;
    }
    REP(i,n+1){
        if(i==n){
            if(cnt!=0){
                num1.PB(cnt) ;
                cnt = 0 ;
            }
            break ;
        }
        if(s[i]=='1'){
            cnt++ ;
        }
        else if(cnt!=0 && s[i]=='0'){
            num1.PB(cnt) ;
            cnt = 0 ;
        }
    }
    if(s[n-1]=='0'){
        num1.PB(0) ;
    }
    REP(i,n+1){
        if(i==n){
            if(cnt!=0){
                num0.PB(cnt) ;
                cnt = 0 ;
            }
            break ;
        }
        if(s[i]=='0'){
            cnt++ ;
        }
        else if(cnt!=0 && s[i]=='1'){
            num0.PB(cnt) ;
            cnt = 0 ;
        }
    }
    vll vec ;
    ll m = SZ(num0) ;
    vec.PB(num1[0]) ;
    REP(i,m){
        vec.PB(num0[i]) ;
        vec.PB(num1[i+1]) ;
    }
    /*
    REP(i,SZ(num1)){
        cout << num1[i] <<" " ;
    }
    cout << endl;
    REP(i,SZ(num0)){
        cout << num0[i] <<" " ;
    }
    cout << endl;
    REP(i,SZ(vec)){
        cout << vec[i] <<" " ;
    }
    cout <<endl;
    */
    

    ll ans = 0 ;

    m = SZ(vec) ;
    vll sum(m,0) ;

    REP(i,2*k+1){
        sum[0] += vec[i] ;
    }
    for(ll i=2;i<=m-(2*k+1);i+=2){
        sum[i] = sum[i-2] - (vec[i-2]+vec[i-1]) + (vec[i+2*k-1] + vec[i+2*k]) ;
    }

    sort(ALL(sum)) ;
    reverse(ALL(sum)) ;
    cout << sum[0] <<endl;
    



    end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count();
    //std::cout << elapsed <<"ms"<< std::endl;

    

    return 0;
}

