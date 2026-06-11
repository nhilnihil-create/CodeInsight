#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main(void){
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        cin >> B[i];
    vector<ll> d(N);
    for (int i = 0; i < N; ++i)
        d[i] = B[i] - A[i];
    ll op_total = accumulate(d.begin(), d.end(), 0LL);
    ll tmp1 = 0, tmp2 = 0;
    for (int i = 0; i < N; ++i){
        if (d[i] < 0) tmp1 -= d[i];
        else tmp2 += (d[i] + 1) / 2;
    }
    string res = (tmp1 <= op_total && tmp2 <= op_total) ? "Yes" : "No";
    cout << res << endl;
    return 0;
}