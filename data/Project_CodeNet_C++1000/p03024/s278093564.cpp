#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    string s; cin >> s;
    int cnt = 0;
    rep(i, 0, s.size()) if(s[i] == 'o') cnt++;
    cnt += 15 - s.size();
    if(cnt >= 8) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
