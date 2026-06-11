#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main()
{
    int N, K, a; cin >> N >> K;
    vector<int> B(N);
    rep(i, N)
    {
        cin >> a;
        B[a - 1]++;
    }

    vector<int> v;
    for(auto p : B) v.push_back(p);
    sort(v.begin(), v.end());
    int d = v.size();
    if (d <= K)
        cout << 0 << endl;
    else
    {
        int ans = 0;
        rep(i, d - K)
        {
            ans += v[i];
        }
        cout << ans << endl;
    }
}