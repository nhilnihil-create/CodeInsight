#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> B(N);
    for (int i = 0; i < N; i++) cin >> B[i];

    ll sum = 0;
    int n = 0;
    vector<int> plus;
    for (int i = 0; i < N; i++) {
        int diff = A[i] - B[i];
        if (diff < 0) { sum -= diff; n++; }
        else plus.push_back(diff);
    }

    if (sum == 0) cout << 0 << endl;
    else {
        int ans = n;
        sort(plus.begin(), plus.end(), greater<int>());
        ll p = 0;
        for (int i = 0; i < plus.size(); i++) {
            p += plus[i];
            ans++;
            if (p >= sum) break;
        }
        if (p >= sum) cout << ans << endl;
        else cout << -1 << endl;
    }

}