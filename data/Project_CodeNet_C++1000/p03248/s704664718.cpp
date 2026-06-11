#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = 2e18;

signed main() {
    string s;
    cin >> s;
    int n = s.length();
    s = '2' + s;
    bool check = true;
    if (s[1] == '0' || s[n] == '1') {
        check = false;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] != s[n - i]) check = false;
    }
    if (!check) {
        cout << -1 << endl;
        return 0;
    }
    s[n] = '1';
    queue<int> temp;
    for (int i = 1; i <= n; i++) if (s[i] == '1') temp.push(i);
    for (int i = 1; i < n; i++) {
        if (i == temp.front()) temp.pop();
        cout << i << " " << temp.front() << endl;
    }
    return 0;
}
