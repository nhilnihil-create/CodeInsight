#include <vector>
#include <iostream>
#include <cmath>
#include <map>
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
#include <sys/time.h>
#include <sys/resource.h>
#include <thread>
#include <chrono>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> vp;
typedef vector<PL> vpl;
typedef vector<vector<P>> vvp;
typedef vector<vector<PL>> vvpl;
const int INF = 1001001001;
const ll LINF = 1e18;
const double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, n) for(ll i = n; i >= 0; i--)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second
#define pb push_back

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
bool pcomp(const PL p1, const PL p2){ return p1.ss*p2.ff < p2.ss*p1.ff;};
template <typename T>
vector<T> uniquen(vector<T> vec){
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

struct stc {ll l, r, v;};

int main(){
    ll N; cin >> N;
    vl T(N+3); T[0] = -1; T[1] = 0;
    rep(i, N){
        cin >> T[i+2]; T[i+2] *= 2; T[i+2] += T[i+1];
    }
    T[N+2] = T[N+1] + 1;
    vl V(N+2, 0);
    rep(i, N){
        cin >> V[i+1]; V[i+1] *= 2;
    }
    
    vector<stc> vs(N+2);
    rep(i, N+2){
        vs[i] = {T[i], T[i+1], V[i]};
    }
    
    vl ans(T[N+1]+1, 0);
    rep(now, T[N+1]+1){
        ll mn = LINF;
        rep(i, N+2){
            auto st = vs[i];
            if(now <= st.l){
                chmin(mn, st.v + abs(now-st.l));
            }
            else if(st.r <= now){
                chmin(mn, st.v + abs(now-st.r));
            }
            else{
                chmin(mn, st.v);
            }
        }
        ans[now] = mn;
    }
    
    double res = 0.0;
    rep(i, T[N+1]){
//        cout << i << " " << ans[i] << endstr;
        res += (double)(ans[i]+ans[i+1])/2.0 / 4.0;
    }
    
    cout << fixed << setprecision(20) << res << endstr;
    return 0;
}
