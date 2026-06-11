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
#define rbg rbegin()
#define red rend()

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

    int n;
    cin >> n;
    vc<string> cities;
    umap<string, vi> city_score;
    umap<int, int> score_index;
    string s;
    int p;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        cin >> p;
        if (city_score.count(s) == 0) {
            cities.push_back(s);
        }
        city_score[s].push_back(p);
        score_index[p] = i;
    }
    for (auto &e : city_score) {
        sort(e.second.rbg, e.second.red);
    }
    sort(cities.bg, cities.ed);
    for (auto &c : cities) {
        for (auto &score : city_score[c]) {
            cout << score_index[score] << endl;
        }
    }
}
