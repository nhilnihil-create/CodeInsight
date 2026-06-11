#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    string t; cin >> t;
    set<string> s;
    int K; cin >> K; K--;
    int n = t.size();
    int cnt = 0;
    rep(i, 5) {
        rep(j, n-i) {
            string x;
            rep(k,i+1) x += t[j+k];
            s.insert(x);
            cnt++;
        }
    }
    auto it = s.begin(); rep(i,K) it++;
    cout << *it;
}
