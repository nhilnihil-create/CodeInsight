#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int N, M; cin >> N >> M;
    vector<int> A(N); for (auto& a : A) cin >> a;

    vector<int> R(N);
    R[0] = A[0] % M;
    for (int i = 1; i < N; i++) {
        R[i] = (R[i-1] + A[i]) % M;
    }

    unordered_map<int, int> cnt;
    cnt[0] = 1;
    for (int r : R) cnt[r]++;

    ll ans = 0;
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
        int c = it->second;
        if (c >= 2) {
            ans += ((ll)c * (c - 1)) / 2;
        }
        
    }
    cout << ans << endl; 
}
