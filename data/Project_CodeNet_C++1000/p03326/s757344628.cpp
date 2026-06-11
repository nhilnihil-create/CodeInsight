#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {
    
    int N, M;
    cin >> N >> M;

    vector<long long> x(N), y(N), z(N);
    rep(i,N) cin >> x[i] >> y[i] >> z[i];

    long long ans = 0;

    rep(k,8) {
        long long sum = 0;
        vector<long long> a(N, 0);
        rep(i,N) {
            a[i] += (k & bit(2) ? x[i] : (-1) * x[i]);
            a[i] += (k & bit(1) ? y[i] : (-1) * y[i]);
            a[i] += (k & bit(0) ? z[i] : (-1) * z[i]);
        }
        sort(a.begin(), a.end(), greater<long long>());
        rep(i,M) sum += a[i];
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}