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
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i,N) {
        cin >> A[i];
        B[i] = A[i] - i;
    }

    sort(B.begin(), B.end());

    int b = N % 2 == 1 ? B[N / 2] : (B[N / 2 - 1] + B[N / 2]) / 2;
    long long ans = 0;
    rep(i,N) ans += abs(B[i] - b);

    cout << ans << endl;

    return 0;
}