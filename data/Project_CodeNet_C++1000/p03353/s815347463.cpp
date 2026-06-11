#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    string s;
    cin >> s;

    int k;
    cin >> k;

    int n;
    n = s.size();

    set<string> st;
    for(int in=0;in<n;in++) {
        for(int jk=1;jk<=k;jk++) {
            st.insert(s.substr(in, jk));
        }
    }

    auto itr = st.begin();
    for(int ik=1;ik<k;ik++) itr++;

    cout << *itr << endl;

    return 0;
}
