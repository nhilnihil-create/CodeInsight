#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    ll res = 0, right = 0, sum = 0;
    for (int left = 0; left < N; left++) {
        while (right < N && (sum ^ A[right]) == (sum + A[right])) {
            sum += A[right];
            right++;
        }

        res += right - left;
        if (left == right)
            right++;
        else
            sum -= A[left];
    }

    cout << res << endl;
}