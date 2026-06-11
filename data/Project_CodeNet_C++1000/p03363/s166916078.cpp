#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    vector<long long> s(N + 1);
    map<long long, long long> m;
    s[0] = 0;
    m[0] = 1;
    for (int i = 1; i <= N; i++) {
        s[i] = s[i - 1] + A[i - 1];
        m[s[i]] += 1;
    }

    long long ans = 0;
    for (auto cur : m) {
        ans += cur.second * (cur.second - 1) / 2;
    }
    cout << ans << endl;
}
