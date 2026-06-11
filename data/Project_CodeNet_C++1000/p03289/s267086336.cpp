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
    string s; cin >> s;
    if (s.at(0) != 'A') {
        cout << "WA";
        exit(0);
    }
    int n = s.size(), cnt = 0;
    rep(i, 2, n-1) {
        if (s.at(i) == 'C') cnt++;
        else if (isupper(s.at(i))) {
            cout << "WA";
            exit(0);
        }
    }
    if (isupper(s.at(1)) || isupper(s.at(n-1))) {
        cout << "WA";
        exit(0);
    }
    (cnt == 1) ? cout << "AC" : cout << "WA";
    return 0;
}