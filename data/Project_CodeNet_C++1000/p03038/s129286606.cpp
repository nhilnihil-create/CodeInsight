#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<pair<ll, int>> ch;

    rep(i, M)
    {
        int b;
        ll c;
        cin >> b >> c;
        ch.push_back(make_pair(c, b));
    }
    sort(ch.rbegin(), ch.rend());

    int now = 0;
    int num = 0;
    rep(i, N)
    {
        num = ch[now].second;
        if (num <= 0) {
            now++;
            if (now >= N)
                break;
        }
        if (ch[now].first < A[i])
            break;
        A[i] = ch[now].first;
        ch[now].second--;
    }
    ll ans = 0;
    rep(i, N)
    {
        ans += A[i];
    }

    cout << ans << endl;
    return 0;
}