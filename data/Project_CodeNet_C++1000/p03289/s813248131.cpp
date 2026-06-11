#include <bits/stdc++.h>
using namespace std;

template <class t>
using vc = vector<t>;
template <class t>
using vvc = vector<vector<t>>;
typedef long long ll;
typedef vc<int> vi;
typedef vvc<int> vvi;
typedef pair<int, int> pi;

#define uset unordered_set
#define umap unordered_map

#define endl "\n"

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()

#define all(a) a.bg, a.ed

template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
    return os << "( " << p.first << ", " << p.second << " )";
}

template <class t>
ostream &operator<<(ostream &os, const vc<t> &v) {
    os << "[ ";
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    return os << " ]";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << setprecision(18);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // Solution

    string s;
    cin >> s;
    if (s[0] != 'A') {
        cout << "WA";
        return 0;
    }
    int ic = -1;
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == 'C') {
            if (ic == -1) {
                ic = i;
            } else {
                cout << "WA";
                return 0;
            }
        }
    }
    if (ic == -1) {
        cout << "WA";
        return 0;
    }
    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z' && i != 0 && i != ic) {
            cout << "WA";
            return 0;
        }
    }
    cout << "AC";
}
