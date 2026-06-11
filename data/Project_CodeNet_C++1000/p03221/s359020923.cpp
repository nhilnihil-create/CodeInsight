#include <bits/stdc++.h>

using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto a: v)
        out << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
    for (auto m: M)
        cout << "(" << m.first << "->" << m.second << ") ";
    return out;
}

template<typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    vector<pair<int, int>> A;
    vector<vector<int>> B;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A.emplace_back(a - 1, b);
    }
    // cout << "A: " << A << endl;
    B.resize(m);
    for (int i = 0; i < m; i++)
        B[i].clear();
    for (int i = 0; i < n; i++)
        B[A[i].first].push_back(A[i].second);
    for (int i = 0; i < m; i++)
        sort(B[i].begin(), B[i].end());
    // cout << "B: " << B << endl;
    for (int i = 0; i < n; i++) {
        int p = lower_bound(B[A[i].first].begin(), B[A[i].first].end(), A[i].second) - B[A[i].first].begin();
        cout << setfill('0') << setw(6) << A[i].first + 1 << setfill('0') << setw(6)  << p + 1 << endl;
    }

    return 0;
}
