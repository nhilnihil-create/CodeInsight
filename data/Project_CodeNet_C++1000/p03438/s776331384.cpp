#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repd(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;
using Graph = vector<vector<int>>; // グラフ型
using pint = pair<int, int>;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    rep(i, N) cin >> A[i];
    vector<long long> B(N);
    rep(i, N) cin >> B[i];
    ll cnt = 0;
    rep(i, N)
    {
        // １の操作が行える分だけ２の操作ができる
        // A[i]  - B[i] = 1 の時は考えない
        // 理由は２の操作ができないから
        if (B[i] - A[i] >= 0)
        {
            cnt += (B[i] - A[i]) / 2;
        }
        // 2の操作は1の操作ができる分だけ行える
        // 逆に１の最大操作回数よりも大きくなるとNo
        else
        {
            cnt += (B[i] - A[i]);
        }
    }
    if (cnt >= 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}