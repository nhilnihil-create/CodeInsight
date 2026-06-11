#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

#ifndef INPUTS_DIR
#define INPUTS_DIR "./"
#endif


int len(const vector<ll> &a, ll lb, ll ub) {
    return (int) (lower_bound(a.begin(), a.end(), ub) - lower_bound(a.begin(), a.end(), lb));
}


void solve(ll N, vector<ll> a, vector<ll> b) {
    int xr = 0;
    for (int i = 0; i < 29; i++) {
        vector<ll> A = a;
        vector<ll> B = b;
        for (auto &&x : A) x %= 2 << i;
        for (auto &&x : B) x %= 2 << i;
        sort(B.begin(), B.end());

        long long ans = 0;
        for (auto &&x : A) {
            ans += len(B, (1 << i) - x, (2 << i) - x);
            ans += len(B, (1 << i) + (2 << i) - x, (4 << i) - x);
        }
        xr |= (1 << i) * (ans % 2);
    }
    cout << xr << endl;
}


void main_(istream &cin) {
    ll N;
    cin >> N;
    vector<ll> a(N - 1 + 1);
    vector<ll> b(N - 1 + 1);
    for (int i = 0; i <= N - 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i <= N - 1; i++) {
        cin >> b[i];
    }
    solve(N, a, b);
}

int main() {
#ifdef INTELLIJ
    ifstream ifs(string(INPUTS_DIR) + "in_1.txt");
    if (ifs.is_open()) {
        main_(ifs);
        ifs.close();
    } else {
        cerr << "Error: no input." << endl;
    }
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
#endif
}



