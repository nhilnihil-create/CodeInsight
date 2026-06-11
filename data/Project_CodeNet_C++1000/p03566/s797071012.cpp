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
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> vp;
typedef vector<PL> vpl;
typedef vector<vector<P>> vvp;
typedef vector<vector<PL>> vvpl;
const int INF = 1001001001;
const ll LINF = 1e10;
const double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define REP(i, n) for(ll i = 0; i < n; i++)
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
template <typename T>
vector<T> uniquen(vector<T> vec){
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}


int main(){
    ll N; cin >> N;
    vl t(110, 0), s(110, 0);
    FOR(i,1, N+1){
        cin >> t[i]; t[i] *= 2;
        s[i+1] = s[i] + t[i];
    }
    vl v(110, 0);
    FOR(i,1, N+1){
        cin >> v[i];
        v[i] *= 2;
    }
    
    vl p(40100, 0);
    FOR(i, 0, s[N+1] + 1){
        FOR(j, 1, N+2){
            if(i <= s[j]){
                p[i] = v[j-1]; break;
            }
        }
        FOR(j, 1, N+2){
            ll dst = abs(s[j] - i);
            p[i] = min(p[i], dst + min(v[j-1],v[j]));
        }
    }
    
    ll ans = 0;
    REP(i, s[N+1]+1){
        ans += p[i];
    }
    double ansd = (double)0.25 * ans;
    cout << fixed << std::setprecision(20) << ansd << endl;
    return 0;
}
