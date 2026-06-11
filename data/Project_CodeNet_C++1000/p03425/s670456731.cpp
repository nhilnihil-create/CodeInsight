//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQG = priority_queue<T, vector<T>, greater<T> >;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
template<typename T1, typename T2>
inline bool chmax(T1 &a, T2 b) {return a < b && (a = b, true);}
template<typename T1, typename T2>
inline bool chmin(T1 &a, T2 b) {return a > b && (a = b, true);}
template<typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) { return is >> p.first >> p.second;}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << p.first << ' ' << p.second;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll box[5] = {};
    rep(i, n) {
        string s;
        cin >> s;
        switch(s[0]) {
            case 'M':box[0]++;break;
            case 'A':box[1]++;break;
            case 'R':box[2]++;break;
            case 'C':box[3]++;break;
            case 'H':box[4]++;break;
        }
    }

    int num[5];
    rep(i, 5) num[i] = i;
    ll ans = 0;
    do{
        ll now = 1;
        rep(i, 3) now *= box[num[i]];
        ans += now;
    } while(next_permutation(num, num+5));
    cout << (ans/12) << endl;
}