#include <bits/stdc++.h>

#define MOD 998244353
// #define INF 100000000000

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


template <class T>
ostream &operator<<(ostream &o, const vector<T>&obj) {
    o << "["; for (int i = 0; i < (int)obj.size(); ++i) o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const vector<vector<T>>&obj) {
    o << "[" << endl; for (int i = 0; i < (int)obj.size(); ++i) o << "  " << obj[i] << endl; o << "]"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U>&obj) {
    o << "(" << obj.first << ", " << obj.second << ")"; return o;
}
template <class T, class U>
ostream &operator<<(ostream &o, const map<T, U>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const set<T>&obj) {
    o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}
template <class T>
ostream &operator<<(ostream &o, const queue<T>&obj) {
    queue<T> obj_cp = obj;
    bool first = true;
    o << "{";
    while (!obj_cp.empty()) { o << (!first ? ", " : "") << obj_cp.front(); obj_cp.pop(); first = false; }
    o << "}"; return o;
}

void print() {
    cout << "\n";
}
template<class Head, class... Body>
void print(Head head, Body... body) {
    cout << head << " ";
    print(body...);
}


int main(int argc, char const *argv[]) {
    int H, W, N;
    cin >> H >> W >> N;
    int s_r, s_c;
    cin >> s_r >> s_c;
    string S, T;
    cin >> S >> T;

    int pos;

    pos = s_c;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'L') {
            if (pos == 1) {
                cout << "NO" << endl;
                return 0;
            } else {
                pos -= 1;
            }
        }
        if (T[i] == 'R' && pos < W) {
            pos += 1;
        }
    }

    pos = s_c;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'R') {
            if (pos == W) {
                cout << "NO" << endl;
                return 0;
            } else {
                pos += 1;
            }
        }
        if (T[i] == 'L' && pos > 1) {
            pos -= 1;
        }
    }

    pos = s_r;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'U') {
            if (pos == 1) {
                cout << "NO" << endl;
                return 0;
            } else {
                pos -= 1;
            }
        }
        if (T[i] == 'D' && pos < H) {
            pos += 1;
        }
    }

    pos = s_r;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'D') {
            if (pos == H) {
                cout << "NO" << endl;
                return 0;
            } else {
                pos += 1;
            }
        }
        if (T[i] == 'U' && pos > 1) {
            pos -= 1;
        }
    }

    cout << "YES" << endl;

    return 0;
}
