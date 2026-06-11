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

bool solve(string& str) {
    int n = str.size();
    if (n == 0 || str[0] != 'A')
        return false;
    if (n < 3)
        return false;
    int num_c = 0;
    int occur_c = 0;
    int l = 2;
    int r = n - 2;
    if (l > r)
        swap(l ,r);
    for (int i = 0; i < n; i++) {
        if (str[i] == 'C') {
            num_c++;
        }
    }
    if (num_c != 1)
        return false;
    for (int i = l; i <= r; i++) {
        if (str[i] == 'C') {
            occur_c++;
        }
    }
    if (occur_c != 1)
        return false;
    for (int i = 0; i < n; i++) {
        if (str[i] != 'A' && str[i] != 'C') {
            if (!(str[i] >= 'a' && str[i] <= 'z')) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    cin >> str;
    if (solve(str))
        cout << "AC" << endl;
    else
        cout << "WA" << endl;
    return 0;
}
