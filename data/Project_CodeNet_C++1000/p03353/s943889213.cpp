#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    string s,t;
    set<string> r;
    int K;
    cin >> s >> K;

    rep(i,K)
        rep(j,s.size()-i)
            r.insert(s.substr(j,i+1));

    for(auto p : r)
        if(--K == 0) {
            cout << p << endl;
            return 0;
        }
}