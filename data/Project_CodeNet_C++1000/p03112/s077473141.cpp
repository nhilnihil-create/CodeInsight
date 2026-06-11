#include <bits/stdc++.h>

#define MOD 1000000007
// #define INF 1000000001

using namespace std;
typedef unsigned long long ull;
typedef long long ll;


template <class T>
ostream &operator<<(ostream &o, const vector<T>&obj) {
    o << "["; for (int i = 0; i < (int)obj.size(); ++i) o << (i > 0 ? ", " : "") << obj[i]; o << "]"; return o;
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

#define INF 100000000000

int main(int argc, char const *argv[]) {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B), x(Q);
    for (int i = 0; i < A; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < B; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < Q; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < Q; ++i) {
        auto s_it = lower_bound(s.begin(), s.end(), x[i]);
        auto t_it = lower_bound(t.begin(), t.end(), x[i]);
        ll s_left = (s_it != s.begin()) ? *prev(s_it) : -1;
        ll s_right = (s_it != s.end()) ? *s_it : -1;
        ll t_left = (t_it != t.begin()) ? *prev(t_it) : -1;
        ll t_right = (t_it != t.end()) ? *t_it : -1;

        // print(s_left, s_right, t_left, t_right);

        ll ans = INF;
        if (s_left >= 0 && t_left >= 0) {
            ll dist = x[i] - min(s_left, t_left);
            ans = min(dist, ans);
            // print("1:", dist);
        }
        if (s_left >= 0 && t_right >= 0) {
            ll dist = min(x[i] + t_right - s_left*2, t_right*2 - x[i] - s_left);
            ans = min(dist, ans);
            // print("2:", dist);
        }
        if (s_right >= 0 && t_left >= 0) {
            ll dist = min(x[i] + s_right - t_left*2, s_right*2 - x[i] - t_left);
            ans = min(dist, ans);
            // print("3:", dist);
        }
        if (s_right >= 0 && t_right >= 0) {
            ll dist = max(s_right, t_right) - x[i];
            ans = min(dist, ans);
            // print("4:", dist);
        }

        cout << ans << endl;
    }
       
    return 0;
}
