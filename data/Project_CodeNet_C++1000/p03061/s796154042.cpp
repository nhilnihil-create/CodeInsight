// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

vector<ll> divisor(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

// 以下は時間がかかりすぎて却下
int old_main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<int, int> mp;
    rep(i, N) {
        vector<ll> divs = divisor(A[i]);
        for (auto d : divs) mp[d]++;
    }

    int res = 1;
    for (auto p : mp) {
        if (p.second == N) {
            res = max(res, p.first);
        }
        else if (p.second == N-1) {
            res = max(res, p.first);
        }
    }

    cout << res << endl;
    return 0;
}

// 開放を変えてチャレンジ
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int res = 0;
    if (N == 2) {
        res = max(A[0], A[1]);
    } else if (N == 3) {
        res = max(gcd(A[0], A[1]), gcd(A[0], A[2]));
        res = max(res, gcd(A[1], A[2]));
    } else {
        res = 1;
        vector<ll> div1 = divisor(gcd(A[0], A[1]));
        vector<ll> div2 = divisor(gcd(A[2], A[3]));

        rep(i, div2.size()) div1.push_back(div2[i]);

        for (auto d : div1) {
            int miss = 0;
            rep(i, N) {
                if (A[i]%d != 0) {
                    miss++;
                    if (miss > 1) {
                        break;
                    }
                }
            }
            if (miss <= 1) {
                res = max(res, (int)d);
            }
        }
    }
    cout << res << endl;
}