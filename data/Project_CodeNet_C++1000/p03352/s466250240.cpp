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

    int x;
    cin >> x;
    if (x == 1) {
        cout << 1;
    } else {
        int closest = -1;
        for (int i = 2; i < x; i++) {
            int cur_val = i;
            int cur_pow = 2;
            while (cur_val <= x) {
                cur_val = pow(i, cur_pow);
                cur_pow++;
            }
            int actual_pow = cur_pow - 2;
            int actual_val = pow(i, actual_pow);
            if (closest < actual_val && actual_pow > 1) {
                closest = actual_val;
            }
        }
        cout << closest;
    }
}
