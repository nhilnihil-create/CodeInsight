#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, M, C;
    int ans = 0;
    cin >> N >> M >> C;
    vector<int> B = vector<int>(M);
    vector<int> A = vector<int>(M);

    rep(i, M) cin >> B[i];

    rep(i, N)
    {
        rep(s, M) cin >> A[s];
        int sum = 0;
        rep(j, M)
        {
            sum += A[j] * B[j];
        }
        sum += C;
        if (sum > 0)
            ans++;
    }
    cout << ans << endl;
}
