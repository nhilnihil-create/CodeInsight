#include <bits/stdc++.h>
using namespace std;
using ipair = pair<int, int>;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1LL<<58;

template<class T> int former(const deque<T> &v, T x){
    return upper_bound(v.begin(), v.end(), x) - v.begin() -1;
}

template<class T> int latter(const deque<T> &v, T x){
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}


int main(){
    int A, B, Q;
    cin >> A >> B >> Q;

    deque<ll> s(A);
    deque<ll> t(B);

    rep(i, A) cin >> s[i];
    rep(i, B) cin >> t[i];

    s.push_front(-INF);
    s.push_back(INF);
    t.push_front(-INF);
    t.push_back(INF);

    rep(_, Q){
        ll x;
        cin >> x;

        ll res = INF;

        // 最初にs, 次にt
        rep(i, 2){
            ll visited_first = i ? s[former(s, x)]: s[latter(s, x)];
            rep(j, 2){
                ll visited_second = j? t[former(t, visited_first)]: t[latter(t, visited_first)];
                chmin(res, abs(visited_first - x) + abs(visited_second - visited_first));
            }
        }
        // 最初にt, 次にs
        rep(i, 2){
            ll visited_first = i ? t[former(t, x)]: t[latter(t, x)];
            rep(j, 2){
                ll visited_second = j? s[former(s, visited_first)]: s[latter(s, visited_first)];
                chmin(res, abs(visited_first - x) + abs(visited_second - visited_first));
            }
        }
        cout << res << endl;
    }

    return 0;
}