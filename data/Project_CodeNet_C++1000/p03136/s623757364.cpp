#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll N; cin >> N;
    vector<int> v(N); for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    ll sum = 0;
    for (int i = 0; i < N - 1; ++i) sum += v[i];
    if (sum > v[N - 1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}