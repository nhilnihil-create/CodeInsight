#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }


int main() {
    string s; cin >> s;
    int k; cin >> k;

    set<string> st;

    rep(i, s.size()) {
        rep(j, s.size()-i+1) {
            st.insert(s.substr(i, j));
            if(j > 5) break;
        }
    }

    // から文字列消すkesu
    st.erase("");
    int i = 1;
    for(auto itr = st.begin(); itr != st.end(); ++itr) {
        if(i == k) {
            cout << *itr << endl;
            break;
        }
        i++;
    }

    return 0;
}
