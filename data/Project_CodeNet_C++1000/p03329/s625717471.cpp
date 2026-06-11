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

//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::chrono::system_clock::time_point start,end;
    start = std::chrono::system_clock::now();
    int n ;
    cin >> n ;
    vector<int> dis(n+1,0) ;
    vector<int> seen(n+1,0) ;
    queue<int> que ;
    vector<int> next ;
    next.push_back(1) ;
    int i6 = 6 ;
    while(i6<=n){
        next.PB(i6) ;
        i6 *= 6 ;
    }
    int i9 = 9 ;
    while(i9<=n){
        next.PB(i9) ;
        i9 *= 9 ;
    }
    
    que.push(0) ;
    seen[0] = 1 ;
    dis[0] = 0 ;

    while(!que.empty()){
        int k = que.front() ;
        que.pop() ;
        for(int i=0;i<next.size();i++){
            if(k+next[i]<=n && seen[k+next[i]]==0){
                que.push(k+next[i]) ;
                seen[k+next[i]] = 1 ;
                dis[k+next[i]] = dis[k] + 1 ;
                if(k+next[i]==n){
                    cout << dis[k+next[i]] <<endl;
                    return 0 ;
                }
            }
        }
    }

    cout << dis[n] <<endl;


    end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count();
    //std::cout << elapsed <<"ms"<< std::endl;

    

    return 0;
}

