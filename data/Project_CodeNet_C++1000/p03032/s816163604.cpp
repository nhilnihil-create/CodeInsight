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
    int N, K;
    cin >> N >> K;
    vector<int> V(N);
    rep(i, N) cin >> V[i];

    int ans = 0;
    rep(l, N + 1) {
        rep(r, N + 1 - l) {
            int k = K - l - r;
            // cout << l << " " << r << endl;
            if (k < 0 || (l + r) <= 0) continue;
            vector<int> num;
            int sum = 0;
            rep(i, l) {
                num.push_back(V[i]);
                sum += V[i];
            }
            rep(i, r) {
                num.push_back(V[N - i - 1]);
                sum += V[N - i - 1];
            }
            sort(all(num));
            rep(i, min(k, (int)num.size())) {
                if (num[i] < 0) {
                    sum -= num[i];
                }
            }
            chmax(ans, sum);
        }
    }

    cout << ans << endl;
    return 0;
}