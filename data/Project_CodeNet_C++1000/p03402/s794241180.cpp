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
    ll A, B; cin >> A >> B; A -= 1; B -= 1;
    
    ll ha = 2 * (A / 50); ll hb = 2 * (B / 50); ll h_all = ha + hb + 4; ll w_all = 100;
    
    vector<string> ans(h_all, "");
    
    // white
    string w_line; REP(i,100) w_line += "."; // white line
    string w_cross; REP(i,100) w_cross += i%2 == 0 ? "#" : ".";
    string b_line; REP(i, 100) b_line += "#"; // black line
    REP(i,ha) ans[i] =  i%2 == 0 ? w_cross : b_line;
    
    ll a_remain = A - 50 * (ha / 2); string w_last = "";
    REP(i, 100){
        if(i < a_remain * 2){
            w_last += (i % 2 == 0) ? "#" : ".";
        }
        else{
            w_last += "#";
        }
    }
    ans[ha] = w_last; ans[ha+1] = b_line;
    
    // black
    ans[ha+2] = w_line;
    FOR(i, ha+3, ha+hb+3) ans[i] = i%2 == 0 ? w_line : w_cross;
    ll b_remain = B - 50 * (hb / 2); string b_last = "";
    REP(i, 100){
        if(i < b_remain * 2){
            b_last += (i % 2 == 0) ? "#" : ".";
        }
        else{
            b_last += ".";
        }
    }
    ans[ha+hb+3] = b_last;
    
    cout << h_all << " " << w_all << endl;
    for(string line : ans) cout << line << endl;
    return 0;
}
