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
int main()
{
    int K;
    vector<int> A(3);
    rep(i, 3) cin >> A[i];

    cin >> K;

    sort(all(A));
    int ans = A[0] + A[1];

    rep(i, K) {
        A[2] *= 2;
    }

    cout << ans + A[2] << endl;
    return 0;
}