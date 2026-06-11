#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define speed() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) (int)(x).size()
#define _USE_MATH_DEFINES
using namespace std;
typedef long long int lli;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    speed();
    string s, t; cin >> s >> t;
    bool ans = false;
    rep(i, 0, s.size()) {
        if (s == t) {
            ans = true;
            break;
        }
        s = s.back() + s.substr(0, s.size()-1);
    }
    ans ? cout << "Yes" : cout << "No";
    return 0;
}