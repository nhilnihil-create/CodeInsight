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
    int N, D, X;
    cin >> N >> D >> X;

    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int ans = X;

    rep(i, N) {
        int j = 0;
        while (1) {
            if (1 + (j * A[i]) <= D) ans++;
            else break;
            j++;
        }
    }

    cout << ans << endl;
    return 0;
}