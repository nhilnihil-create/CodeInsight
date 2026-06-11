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
const ll LINF = 1e17;
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

struct edge {ll to, cost;};

int main(){
    ll N; cin >> N;
    vl D(N); REP(i, N) cin >> D[i];
    vl fix, sel; map<ll, ll> cnt;
    REP(i, N){
        cnt[D[i]]++;
        if(cnt[D[i]] >= 3 || D[i] == 0){
            cout << 0 << endl; return 0;
        }
    }
    FORMAP(it, cnt){
        if(it->ss == 2){
            fix.pb(it->ff); fix.pb(24-it->ff);
        }
        else if(it->ss == 1){
            sel.pb(it->ff);
        }
    }
    
    ll M = sel.size(); ll ans = 0;
    REP(i, 1ll << M){
        vl cand;
        REP(j, M){
            if(i >> j & 1) cand.pb(sel[j]);
            else cand.pb(24-sel[j]);
        }
        vl tmp = fix;
        tmp.pb(0);
        REP(j, M) tmp.pb(cand[j]);
        
        ll an = LINF;
        REP(j, tmp.size()){
            FOR(k, j+1, tmp.size()){
                ll mnt = min(tmp[j], tmp[k]);
                ll mxt = max(tmp[j], tmp[k]);
                ll t = mxt - mnt;
                an = min(an, min(t, 24-t));
            }
        }
        
        ans = max(ans, an);
    }
    cout << ans << endl;
    return 0;
}
