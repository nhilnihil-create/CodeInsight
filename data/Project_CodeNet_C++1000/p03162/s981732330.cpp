#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> a(N+1), b(N+1), c(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<int> aa(N+1, a[1]), bb(N+1, b[1]), cc(N+1, c[1]);
    for (int i = 2; i <= N; i++) {
        aa[i] = max(bb[i-1], cc[i-1]) + a[i];
        bb[i] = max(aa[i-1], cc[i-1]) + b[i];
        cc[i] = max(bb[i-1], aa[i-1]) + c[i];
    }

    cout << max({aa[N], bb[N], cc[N]}) << endl;
}