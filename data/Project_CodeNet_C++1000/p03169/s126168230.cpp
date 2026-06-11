#include <stdio.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <iomanip>

using namespace std;
using ll = int64_t;
using VL = vector<ll>;
using VD = vector<double>;
using VVL = vector<VL>;
using VVD = vector<VD>;

#define FOR(i, start, end) for(ll i = (start), (i ## xxxx_end)=(end); i < (i ## xxxx_end); ++i)
#define FORD(i, start, end) for(ll i = (start), (i ## xxxx_end)=(end); i > (i ## xxxx_end); --i)
#define REP(i, n) FOR(i, 0, n)
#define REPD(i, n) FORD(i, n - 1, -1)

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

template<class T, class U>bool chmax(T &a, const U &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T, class U>bool chmin(T &a, const U &b) { if (b<a) { a=b; return 1; } return 0; }

template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}

#define INF 1000000000000
#define MOD 1000000007

ll N;
VL A;
vector<VVD> dp;

double f(ll d1, ll d2, ll d3) {
    if(dp[d1][d2][d3] >= 0)
        return dp[d1][d2][d3];

    if(d1 + d2 + d3 == 0.0)
        return 0;

    double ret = N;
    if(d1 > 0) 
        ret += f(d1 - 1, d2, d3) * d1;
    if(d2 > 0)
        ret += f(d1 + 1, d2 - 1, d3) * d2;
    if(d3 > 0)
        ret += f(d1, d2 + 1, d3 - 1) * d3;
    return (dp[d1][d2][d3] = ret / (d1 + d2 + d3));
}

void solve() {
    cin >> N;
    A = VL(4, 0);
    REP(i, N) {
        ll a;
        cin >> a;
        ++A[a];
    }
    dp = vector<VVD>(310, VVD(310, VD(310, -1)));
    printf("%.10lf\n", f(A[1], A[2], A[3]));
}

int main() {
    solve();
    return 0;
}