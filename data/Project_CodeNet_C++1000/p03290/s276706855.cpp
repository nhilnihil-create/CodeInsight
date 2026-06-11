#include <bits/stdc++.h>

#define MOD 1000000007
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


void display_base(int n, int b) {
    vector<int> v;
    int n_ = n;
    while(n_ > 0) {
        v.push_back(n_ % b);
        n_ /= b;
    }
    cout << n << "(" << b << ") = ";
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }
    cout << endl;
}


int main(int argc, char const *argv[]) {
    int D, G;
    cin >> D >> G;
    G /= 100;

    vector<int> p(D);
    vector<ll> c(D);
    for (int i = 0; i < D; ++i) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }

    vector<int> dp(1 << D, 0);
    for (int s = 0; s < (1 << D); ++s) {
        for (int i = 0; i < D; ++i) {
            if (!(s & (1 << i))) {
                dp[s | 1 << i] = dp[s] + (i + 1) * p[i] + c[i];
            }
        }
    }

    int ans = 1001;
    for (int s = 0; s < (1 << D); ++s) {
        int base = 0;
        for (int i = 0; i < D; ++i) {
            if (s & (1 << i)) {
                base += p[i];
            }
        }

        if (dp[s] >= G) {
            ans = min(ans, base);
            continue;
        }

        int res = -1;
        for (int i = D-1; i >= 0; --i) {
            if (s & (1 << i)) continue;
            int c = (G - dp[s] + i) / (i+1);
            if (c < p[i]) {
                res = c;
            }
            break;
        }
        if (res == -1) continue;

        // display_base(s, 2);
        // print(base, res);
        ans = min(ans, base + res);
    }
    // print(dp);

    cout << ans << endl;

    return 0;
}
