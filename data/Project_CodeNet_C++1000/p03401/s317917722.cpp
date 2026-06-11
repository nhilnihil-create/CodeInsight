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
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    vector<long long> from(N, 0), to(N, 0);
    from[0] = abs(A[0]);
    to[N - 1] = abs(A[N - 1]);
    for (int i = 1; i < N; i++) {
        from[i] = from[i - 1] + abs(A[i] - A[i - 1]);
        to[N - 1 - i] = to[N - i] + abs(A[N - i] - A[N - i - 1]);
    }
    rep(i,N) {
        if (i == 0) cout << abs(A[1]) + to[1] << endl;
        else if (i == N - 1) cout << from[N - 2] + abs(A[N - 2]) << endl;
        else cout << from[i - 1] + abs(A[i + 1] - A[i - 1]) + to[i + 1] << endl;
    }
    
    return 0;
}