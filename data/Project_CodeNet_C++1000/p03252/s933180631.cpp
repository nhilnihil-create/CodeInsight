#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

int main() {
    string s, t;
    cin >> s >> t;
    map<char, int> m;
    rep (i, 26) {
        int c = 'a' + i;
        vector<int> places;
        rep (j, s.size()) {
            if (s[j] == c) {
                places.push_back(j);
            }
        }
        if (places.empty()) {
            continue;
        }
        if (m[t[places[0]]] == 1) {
            cout << "No" << endl;
            exit(0);
        }
        rep (j, places.size()) {
            if (t[places[0]] != t[places[j]]) {
                cout << "No" << endl;
                exit(0);
            }
        }
        m[t[places[0]]] = 1;
    }
    cout << "Yes" << endl;
}