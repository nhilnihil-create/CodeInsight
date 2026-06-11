/**
*    created: 27.06.2020 19:11:46
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcountll(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    if (s[0] != 'A' || !islower(s[1]) || !islower(s[s.size()-1])) {
        cout << "WA" << endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 2; i <= s.size()-2; i++) {
        if (s[i] == 'C') {
            if (cnt == 1) {
                cout << "WA" << endl;
                return 0;
            }
            else cnt++;
        }
        else if (!islower(s[i])) {
            cout << "WA" << endl;
            return 0;
        }
    }
    if (cnt == 0) {
        cout << "WA" << endl;
        return 0;
    }
    cout << "AC" << endl;
    return 0;
}