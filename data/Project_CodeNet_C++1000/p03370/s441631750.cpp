#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
#define INF __INT32_MAX__

int main() {
    int N, X;
    cin >> N >> X;
    vi M(N);
    int sum = 0;
    rep(i, N) {
        cin >> M[i];
        sum += M[i];
    }

    X -= sum;

    int mmin = *min_element(M.begin(), M.end());
    cout << (N + (X / mmin)) << endl;
}