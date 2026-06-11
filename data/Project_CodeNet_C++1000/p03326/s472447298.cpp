#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>
#include <functional>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define MOD 1000000007LL
#define rep(i,a,n) for (int i=a ; i<n ; i++)
#define per(i,a,n) for (int i=n-1 ; i>=a ; i--)
#define LLINF 100000000000000005LL
#define INF (int)1e9+1
#define endl '\n'
#define pb push_back

// debug 도구

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string)s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}\n";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)

// debug 도구 end

using llong = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VPII = vector<pair<int, int>>;
using VLL = vector<long long>;
using PII = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    VLL x(n), y(n), z(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i] >> z[i];
    }
    llong maxScore = 0;
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            rep(k, 0, 2) {
                llong score = 0;
                llong xx = 0, yy = 0, zz = 0;
               
                llong xxx = (i == 0) ? 1 : -1;
                llong yyy = (j == 0) ? 1 : -1;
                llong zzz = (k == 0) ? 1 : -1;
                vector<pair<llong, int>> newSum;
                rep(ttt, 0, n) {
                    newSum.push_back({ x[ttt] * xxx + y[ttt] * yyy + z[ttt] * zzz,ttt });
                }
                sort(newSum.rbegin(),newSum.rend());
                rep(ttt, 0, m) {
                    xx += x[newSum[ttt].ss];
                    yy += y[newSum[ttt].ss];
                    zz += z[newSum[ttt].ss];
                }
              
                score = abs(xx) + abs(yy) + abs(zz);
       
                maxScore = max(score, maxScore);
            }
        }
    }
    cout << maxScore << endl;
    return 0;
}