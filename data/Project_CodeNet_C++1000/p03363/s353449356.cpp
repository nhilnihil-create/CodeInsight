#include <iostream>
#include <map>
using namespace std;
#define ll long long

const int MAX_N = 200009;

int N, A[MAX_N];

ll s[MAX_N];
map<ll, ll> M;

int main() {
    s[0] = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        s[i+1] = s[i] + A[i];
    }

    for (int i = 0; i <= N; i++) {
        M[s[i]]++;
    }

    ll ans = 0;
    for (auto it : M) {
        ll n = it.second;
        ans += n * (n-1) / 2;
    }

    cout << ans << endl;
    return 0;
}