#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int Q;
    cin >> Q;
    vector<int> cnt(1e5 + 2, 0);
    repd(i, 3, 1e5 + 1) {
        if (i % 2) {
            if (isPrime(i) && isPrime((i + 1) / 2)) {
                cnt[i]++;
            }
        }
    }

    repd(i, 1, cnt.size()) {
        cnt[i] += cnt[i - 1];
    }

    rep(i, Q) {
        int l, r;
        cin >> l >> r;

        cout << cnt[r] - cnt[l - 1] << endl;
    }
    return 0;
}