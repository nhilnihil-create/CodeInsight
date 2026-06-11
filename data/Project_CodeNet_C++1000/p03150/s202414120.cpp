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

#define endl "\n"

#define k first
#define v second
#define pb push_back
#define mp make_pair
#define bg begin()
#define ed end()

#define ALL(a) a.bg, a.ed

template <class t, class u>
ostream &operator<<(ostream &os, const pair<t, u> &p) {
    return os << "( " << p.k << ", " << p.v << " )";
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

// g++ -std=c++17 -O2 -Wall template.cpp -o template
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout << fixed << setprecision(18);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // Solution

    string s;
    cin >> s;
    string ref = "keyence";
    int si = 0;
    bool end = false;
    for (int i = 0; i < ref.size(); i++) {
        if (ref[i] == s[si]) {
            si++;
        } else {
            if (end) {
                cout << "NO\n";
                return 0;
            }
            end = true;
            i--;
            si = s.size() - ref.size() + i + 1;
        }
    }
    cout << "YES\n";
    // vector<vector<string>> meme;
    // for (int i = 1; i < ref.size(); i++) {
    //     auto left = ref.substr(0, i);
    //     auto right = ref.substr(i);
    //     meme.push_back({left, right});
    // }
    // if (s.find(ref) != string::npos) {
    //     cout << "YES\n";
    //     return 0;
    // }
    // for (auto &m : meme) {
    //     bool bad = false;
    //     for (int i = 0; i < m[0].size(); i++) {
    //         if (m[0][i] != s[i]) {
    //             bad = true;
    //             break;
    //         }
    //     }
    //     if (bad) {
    //         continue;
    //     }
    //     for (int i = m[1].size() - 1; 0 <= i; i--) {
    //         if (m[1][i] != s[i]) {
    //             bad = true;
    //             break;
    //         }
    //     }
    //     if (!bad) {
    //         cout << "YES\n";
    //         return 0;
    //     }
    // }
    // cout << "NO\n";
}
