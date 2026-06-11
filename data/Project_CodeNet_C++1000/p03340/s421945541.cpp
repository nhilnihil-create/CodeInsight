#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    int N;
    cin >> N;
    vl A(N);
    rep(i, N) {
        cin >> A[i];
    }

    ll sum = 0;
    ll cnt = 0;
    int r = 0;
    for (int l = 0; l < N; l++) {
        while (r < N && ((sum + A[r]) == (sum ^ A[r]))) {
            sum += A[r];
            r++;
        }

        cnt += r - l;

        if (r == l) {
            r++;
        } else {
            sum -= A[l];
        }
    }

    cout << cnt << endl;
}