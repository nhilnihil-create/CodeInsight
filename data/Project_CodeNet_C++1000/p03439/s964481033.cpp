#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

ll f(string s) {
    if (s == "Male") return 0;
    else return 1;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    ll low = 0, high = n;
    cout << 0 << endl;
    string s;
    cin >> s;
    if (s == "Vacant") {
        return 0;
    }
    ll fir = f(s);
    while((low + 1) < high) {
        ll mid = (low + high) / 2;
        cout << mid << endl;
        cin >> s;
        if (s == "Vacant") {
            return 0;
        }
        if (mid % 2 == 0) {
            if (f(s) != fir) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        else {
            if (f(s) != fir) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
    }
    cout << low << endl;
    cin >> s;
    return 0;
}
