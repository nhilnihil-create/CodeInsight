#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
typedef long long ll;
const int mod = 1e9 + 7;
int main() {

    string s;
    int k;
    cin >> s >> k;

    set<string> st;
    rep(i, s.size()){
        for(int j=1; j < s.size()-i+1 && j <= k; ++j){
            st.insert(s.substr(i, j));
        }
    }
    int i = 1;
    for(auto itr = st.begin(); itr != st.end(); ++itr, ++i) {
        if(i == k)
            cout << *itr;
    }

    return 0;
}