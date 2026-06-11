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

int query_value(vector<int>& A) {
    int n = A.size();
    int val = 0;
    for (int i = 0; i < n; i++) {
        val = (val + 9) / 10 * 10;
        val += A[i];
    }
    return val;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n = 5;
    int min_val = 1e9;
    vector<int> A;
    A.resize(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    do {
        int val = query_value(A);
        min_val = min(min_val, val);
    } while (next_permutation(A.begin(), A.end()));
    cout << min_val << endl;
    return 0;
}
