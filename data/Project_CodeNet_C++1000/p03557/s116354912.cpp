#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N);
    rep(i, N) cin >> A.at(i);
    rep(i, N) cin >> B.at(i);
    rep(i, N) cin >> C.at(i);

    // B固定で考える
    ll count = 0, BAcount = 0, BCcount = 0;
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    vector<int>::iterator iter;
    //　N^2
    rep(i, N) {  // Bのループ
        iter = lower_bound(A.begin(), A.end(), B.at(i));
        ll indexA = iter - A.begin();
        BAcount = indexA;

        iter = upper_bound(C.begin(), C.end(), B.at(i));
        ll indexC = iter - C.begin();
        BCcount = N - indexC;

        count += BAcount * BCcount;
    }

    cout << count << endl;

    return 0;
}