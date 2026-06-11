#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <set>
#include <stack>
#include <cassert>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> vp;
typedef vector<PL> vpl;
typedef vector<vector<P>> vvp;
typedef vector<vector<PL>> vvpl;
const int INF = 1001001001;
const ll LINF = 1e16;
const double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define RFOR(i, a, b) for(ll i = (a); i > b; i--)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define RREP(i, n) for(ll i = n-1; i > -1; i--)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second
#define pb push_back
#define epb emplace_back

template <typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b%a, a);
}
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

bool p_comp_fs(const PL p1, const PL p2){ return p1.first < p2.first;};
bool p_comp_fg(const PL p1, const PL p2){ return p1.first > p2.first;};
bool p_comp_ss(const PL p1, const PL p2){ return p1.second < p2.second;};
bool p_comp_sg(const PL p1, const PL p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec){
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}


char nxt[305][305];
char cur[305][305];

int main(){
    ll N; cin >> N;
    REP(i, N) REP(j, N) cin >> cur[i][j];
    
    ll ans = 0;
    FOR(c, 0, N){
        bool ok = true;
        
        REP(i, N) REP(j, N){
            nxt[i][j] = cur[(i+1)%N][j];
        }
        
        REP(i, N){
            REP(j, N){
                if(nxt[i][j] != nxt[j][i]){
                    ok = false; break;
                }
            }
            if(!ok) break;
        }
        if(ok){
            ans += N;
        }
        
        REP(i, N) REP(j, N) cur[i][j] = nxt[i][j];
    }
    cout << ans << endstr;
    return 0;
}
