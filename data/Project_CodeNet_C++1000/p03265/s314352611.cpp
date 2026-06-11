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

using point = complex<double>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    point p1(x1, y1);
    point p2(x2, y2);
    point p3 = p2 + (p2 - p1) * polar<double>(1.0, acos(0.0));
    point p4 = p3 + (p3 - p2) * polar<double>(1.0, acos(0.0));
    int x3 = round(p3.real());
    int y3 = round(p3.imag());
    int x4 = round(p4.real());
    int y4 = round(p4.imag());
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    return 0;
}
