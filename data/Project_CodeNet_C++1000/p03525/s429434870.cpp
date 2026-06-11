#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STI(s) atoi(s.c_str())
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int INF = INT_MAX;
const ll LLINF = 1LL<<60;

int B;
int debug = 6100;

bool cmp(const int &a, const int &b) {
    if(a < B && b < B) return a < b;
    else if(a >= B && b >= B) return a < b;
    else return a >= B;
}

bool dist(int a, int b, int diff){
    if(a>b)swap(a,b);
    return (b - a >= diff) && (a + 24 - b >= diff);
}

bool judge2(int a, int b, vi v, map<pair<int, int>, int> m) {
    sort(all(v), cmp);
    if(b - a == debug)cout<<"ここjudge2 "<<a<<" "<<b<<endl;
    int prev = b;
    int diff = b - a;
    bool cha = 1;
    bool chb = 1;
    rep(i, v.size()){
        if(m.count(mp(v[i], 24 - v[i])) && v[i] == a && cha) {
            cha = 0;
            if(b - a == debug)cout<<"cha"<<endl;
            if(m[ mp(v[i], 24 - v[i]) ] > 1) m[ mp(v[i], 24 - v[i]) ]--;
            else m.erase(m.find( mp(v[i], 24 - v[i]) ));
            if(m[ mp(24 - v[i], v[i]) ] > 1) m[ mp(24 - v[i], v[i]) ]--;
            else m.erase(m.find( mp(24 - v[i], v[i]) ));
            continue;
        }
        else if(m.count(mp(v[i], 24 - v[i])) && v[i] == b && chb) {
            chb = 0;
            if(b - a == debug)cout<<"chb"<<endl;
            if(m[ mp(v[i], 24 - v[i]) ] > 1) m[ mp(v[i], 24 - v[i]) ]--;
            else m.erase(m.find( mp(v[i], 24 - v[i]) ));
            if(m[ mp(24 - v[i], v[i]) ] > 1) m[ mp(24 - v[i], v[i]) ]--;
            else m.erase(m.find( mp(24 - v[i], v[i]) ));
            continue;
        }
        if(b - a == debug)cout<<i<<" "<<v[i]<<" "<<prev<<endl;
        if(m.count(mp(v[i], 24 - v[i]))) { // 使える
            if( dist(v[i], prev, diff) && dist(v[i], a, diff) ) { // おける
                if(b - a == debug)cout<<"if"<<endl;
                prev = v[i];
                if(m.count( mp(24 - v[i], v[i]) )) {
                    if(m[ mp(24 - v[i], v[i]) ] > 1) m[ mp(24 - v[i], v[i]) ]--;
                    else m.erase(m.find( mp(24 - v[i], v[i]) ));
                }
                
                if(m.count( mp(v[i], 24 - v[i]) )) {
                    if(m[ mp(v[i], 24 - v[i]) ] > 1) m[ mp(v[i], 24 - v[i]) ]--;
                    else m.erase(m.find( mp(v[i], 24 - v[i]) ));
                }
            } else {
                if(b - a == debug)cout<<"else"<<endl;
                if(m[ mp(v[i], 24 - v[i]) ] > 1) m[ mp(v[i], 24 - v[i]) ]--;
                else m.erase(m.find( mp(v[i], 24 - v[i]) ));
                
                if(m.count(mp(24 - v[i], v[i]))) { // 次ある
                    continue;
                } else {
                    
                    return false;
                }
            }
        }
    }
    if(prev == a || prev == b)return 1;
    else  return dist(prev, a, diff) && dist(prev, a, diff);
    // return 1;
}

bool judge(int diff, vi d, int n) {
    // cout<<"ここjudge1"<<endl;
    map<pair<int, int>, int> m;
    vi v;
    rep(i, d.size()) {
        m[ mp(d[i], 24 - d[i]) ]++;
        m[ mp(24 - d[i], d[i]) ]++;
        v.push_back(d[i]);
        v.push_back(24 - d[i]);
    }
    for(int i = 0; i < d.size(); i++) {
        int a = d[i];
        int b = d[i] + diff;
        B = b;
        if(b > 24) continue;
        if(judge2(a, b, v, m)) {
            return true;
        } else {}
    }
    return false;
}

int main(void) {

    int n;
    cin >> n;
    vi d(n);
    d.push_back(0);
    rep(i, n) cin >> d[i];
    for(int i = 12; i > 0; i--) {
        if(judge(i, d, n)) {
            fin(i);
            return 0;
        }
    }
    fin(0);
}
