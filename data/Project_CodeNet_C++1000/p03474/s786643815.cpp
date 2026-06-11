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
    int a, b; cin >> a >> b;
    string s; cin >> s;
    rep(i, 0, a) {
        if (!('0' <= s[i] && s[i] <= '9')) {
            cout << "No";
            exit(0);
        }
    }
    if (s[a] != '-') {
        cout << "No";
        exit(0);
    }
    rep(i, a+1, a+b+1) {
        if (!('0' <= s[i] && s[i] <= '9')) {
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes";
    return 0;
}