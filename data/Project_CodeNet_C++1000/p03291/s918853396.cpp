#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef vector<lint> vlint;

#define inf 1e+9
#define endl "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

#define pb push_back
#define eb emplace_back
#define Size(c) (int)(c).size()

#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <class T, class S> inline bool chmax(T &a, S b) {
    if(a < b) {a = b;return 1;} return 0;
}
template <class T, class S> inline bool chmin(T &a, S b) {
    if(a > b) {a = b;return 1;} return 0;
}
template <class T>
void line(vector<T> &x){for (auto&& xi : x) cin >> xi;}

inline void IN(void){ return;}

template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){ cin >> first; IN(rest...); return;}

#define INT(...) int __VA_ARGS__; IN (__VA_ARGS__)
#define LINT(...) lint __VA_ARGS__; IN (__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)

template <class T> void UNIQUE(vector<T> &x) {
    sort(all(x)); x.erase(unique(all(x)), x.end());
}
template <class T> void print_vec(T first, T end){
    for (auto i = first; i < end - 1; i++) cout << *i << " ";
    cout << *(end-1) << endl;
}
template <class T> void print(T a){ cout << a << endl;};
vector<string> Yes = {"No", "Yes"};
vector<string> YES = {"NO", "YES"};

lint stl(char x){
    return (lint)(x - 'a');
}


int main(){
    lint mod = 1e9+7;
    STR(s); int n = Size(s);
    vlint a(n+1, 0), c(n+1, 0), ql(n+1, 0), qr(n+1, 0);
    vlint Exp(n+1, 1);
    rep(i, n){
        if (s[i] == 'A') a[i] ++;
        if (s[i] == '?') ql[i] ++;
        a[i+1] += a[i]; a[i+1] %= mod;
        ql[i+1] += ql[i]; ql[i+1] %= mod;
        Exp[i+1] = Exp[i] * 3 % mod;
    }
    for (int i = n-1; i > 0; i--){
        if (s[i] == 'C') c[i] ++;
        if (s[i] == '?') qr[i] ++;
        c[i-1] += c[i]; c[i-1] %= mod;
        qr[i-1] += qr[i]; qr[i-1] %= mod;
    }

    lint ans = 0;
    rep1(i, n-1){
        if (s[i] == 'B' || s[i] == '?'){
            ans += a[i-1] * c[i+1] % mod * Exp[ql[i-1] + qr[i+1]] % mod; ans %= mod;
            ans += ql[i-1] * c[i+1] % mod * Exp[ql[i-1] + qr[i+1] - 1] % mod; ans %= mod;
            ans += a[i-1] * qr[i+1] % mod * Exp[ql[i-1] + qr[i+1] - 1] % mod; ans %= mod;
            ans += ql[i-1] * qr[i+1] % mod * Exp[ql[i-1] + qr[i+1] - 2] % mod; ans %= mod;
        }
    }
    
    print(ans);
}
