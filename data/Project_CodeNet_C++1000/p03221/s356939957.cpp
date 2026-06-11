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
typedef vector<vector<int> > vvint;
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;
typedef priority_queue<int, vector<int>, greater<int> > spqint; //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, greater<ll> > spqll;     //小さい順に取り出し
typedef priority_queue<int, vector<int>, less<int> > bpqint;    //大きい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll> > bpqll;        //大きい順に取り出し

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define MOD 1000000007
#define NIL -1
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

const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     //最小公倍数

void yes(){
    cout << "Yes" << endl;
}
void no(){
    cout << "No" << endl;
}
//-----------------------------------------

string str(int x){
    string res = TS(x) ;
    while(SZ(res)!=6){
        res = "0" + res ;
    }
    return res ;
}

//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m ;
    cin >> n >> m ;
    vector<tuple<int,int,int>> vec(m) ;
    REP(i,m){
        int a, b ;
        cin >> a >> b ;
        vec[i] = MT(b,a-1,i) ;
    }
    sort(ALL(vec)) ;
    vint cnt(n,1) ;
    vector<pii> ans(m) ;
    REP(i,m){
        int q, w, e ;
        q = get<0>(vec[i]) ;
        w = get<1>(vec[i]) ;
        e = get<2>(vec[i]) ;
        ans[e] = MP(w,cnt[w]) ;
        cnt[w]++ ;
    }
    REP(i,m){
        cout << str(ans[i].FI+1) <<str(ans[i].SE) <<endl ;
    }

    

    return 0;
}

